/**
 * #1286 Iterator for Combination
 *
 * Design an Iterator class, which has:
 *
 *  - A constructor that takes a string characters of sorted
 *    distinct lowercase English letters and a number combinationLength
 *    as arguments.
 *
 *  - A function next() that returns the next combination of
 *    length combinationLength in lexicographical order.
 *
 *  - A function hasNext() that returns True if and only if
 *    there exists a next combination.
 *
 */

class CombinationIterator {
private:
	string pool_;
	int n_;
	int r_;
	vector<int> indices_;

	void nextIndices() {
		for (int i = r_ - 1; i >= 0; i--) {
    		if (indices_[i] < n_ + i - r_) {
    			int new_index = indices_[i] + 1;
    			for (int j = i; j < r_; j++) {
    				indices_[j] = new_index;
    				new_index++;
    			}
    			break;
    		}
    	}
	}

public:
    CombinationIterator(string characters, int combination_length) {
    	pool_ = characters;
    	n_ = characters.length();
    	r_ = combination_length;
    }
    
    // O(n) time
    string next() {
    	if (indices_.empty()) {
    		for (int i = 0; i < r_; i++) {
    			indices_.push_back(i);
    		}
    	} else {
    		nextIndices();
    	}

    	string s = "";
    	for (int i : indices_) {
    		s.push_back(pool_[i]);
    	}

    	return s;
    }
    
    // O(1) time
    bool hasNext() {
        return indices_.empty() || indices_[0] < n_ - r_;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
