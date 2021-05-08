class PhoneDirectory {
	private:
		unordered_set<int> freeSlots;
	public:
		PhoneDirectory(int maxNum) {
            for(int i=0; i<maxNum; ++i)
                freeSlots.insert(i);
		}
			
		int get() {
			int ret = -1;
			
			if(!freeSlots.empty()) {
				ret = *(freeSlots.begin());
				freeSlots.erase(freeSlots.begin());
			}
			return ret;
		}
		
		bool check(int number) {
			return (!freeSlots.empty() && 
                    (freeSlots.find(number) != freeSlots.end()));	
		}
		
		void release(int number) {
            if(freeSlots.find(number) == freeSlots.end())
			    freeSlots.insert(number);
		}
};