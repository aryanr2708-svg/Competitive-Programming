class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int availableCounts[10] = {0};
    for (int d : digits) {
        availableCounts[d]++;
    }
    int uniqueEvenCount = 0;
    for (int num = 100; num <= 999; num += 2) {
        int hundred = num / 100;
        int ten = (num / 10) % 10;
        int unit = num % 10;
        int requiredCounts[10] = {0};
        requiredCounts[hundred]++;
        requiredCounts[ten]++;
        requiredCounts[unit]++;
        if (requiredCounts[hundred] <= availableCounts[hundred] &&
            requiredCounts[ten] <= availableCounts[ten] &&
            requiredCounts[unit] <= availableCounts[unit]) {
            uniqueEvenCount++;
        }
    }
    return uniqueEvenCount;
    }
};