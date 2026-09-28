// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

// Runtime Beats: 83.51%        Memory Beats: 27.37%

class RandomizedSet {
  private:
    vector<int> nums;
    unordered_map<int, int> mp;

  public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end())
            return false;

        mp[val] = nums.size();
        nums.emplace_back(val);

        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;

        int lastEle = nums.back();
        mp[lastEle] = mp[val];
        nums[mp[val]] = lastEle;

        nums.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        if (nums.empty())
            return -1;

        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */