# LeetCode Daily Challenges

This repository contains my solutions to various LeetCode problems. I don't solve them daily, but I keep track of all
the problems I solve and store them here. The repository is organized based on a naming convention that helps in
identifying the problem difficulty, problem number, and solution approach.

## Repository Structure

Each solution follows a specific file naming and organization pattern:

-   **File Naming Convention**:
    Every solution file is named in the format:
    `M1234.Problem Title.cpp`

Where:

-   `M` stands for **Medium** difficulty.
    (Other possible values are: `E` for Easy, `H` for Hard)
-   `1234` is the **problem number** on LeetCode.
    (e.g., for LeetCode problem number 1234, the file name would be `M1234.`)
-   `Problem Title` is a short, hyphenated version of the problem name.
-   `.cpp` is the extension indicating that the solution is written in C++.

**Inside the Code**:
Every solution contains the following structure:

-   **First Line**:
    A comment with the **LeetCode problem link**.
    Example:
    `// https://leetcode.com/problems/find-the-original-typed-string-i/description/`
-   **Runtime and Memory Comment**:
    The next two lines contain comments about the performance of the solution:
-   **Runtime**: The percentage of faster solutions compared to others.
    Example:
    `// Runtime: 100% faster than other solutions`
-   **Memory**: The percentage of memory-efficient solutions.
    Example:
    `// Memory: 83% less memory than other solutions`
-   **Solution Code**:
    The actual C++ code solving the problem.

**Folder Structure**:
If a folder exists instead of a single `.cpp` file, it means that there are multiple solutions for a given problem.
These solutions may vary in:

-   Improved runtime
-   Optimized memory usage
-   Shortened code for better readability or efficiency

The folder may contain several `.cpp` files, each representing a different approach or optimization.

## Example

### File: `E3330. Find the Original Typed String I.cpp`

```cpp
// Problem Link: https://leetcode.com/problems/find-the-original-typed-string-i/description/

// Runtime: 100% faster than other solutions
// Memory: 83% less memory than other solutions

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int freq = 0;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (word[i - 1] != word[i]) {
                ans += freq;
                freq = 0;
            } else {
                freq++;
            }
        }
        ans += freq;
        return ans;
    }
};
```
