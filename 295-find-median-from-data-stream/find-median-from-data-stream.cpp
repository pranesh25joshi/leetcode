class MedianFinder {
public:
    // Max heap for left half (stores smaller numbers)
    priority_queue<int> leftMax;

    // Min heap for right half (stores larger numbers)
    priority_queue<int, vector<int>, greater<int>> rightMin;

    MedianFinder() {
        // Nothing special needed in constructor
    }
    
    void addNum(int num) {
        // Step 1: Always add to leftMax first
        leftMax.push(num);

        // Step 2: Balance by moving the largest of leftMax to rightMin
        rightMin.push(leftMax.top());
        leftMax.pop();

        // Step 3: Maintain size property (leftMax >= rightMin)
        if (leftMax.size() < rightMin.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        // If odd → leftMax will have extra element
        if (leftMax.size() > rightMin.size()) {
            return leftMax.top();
        } 
        // If even → median is avg of tops
        else {
            return (leftMax.top() + rightMin.top()) / 2.0;
        }
    }
};
