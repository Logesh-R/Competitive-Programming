class HitCounter {
	private:
		queue<int> hitTimeStamps;
	
	public:
		//Removing the uninterestedHits from queue
		void uninterestedHitRemover(int currTimeStamp) {
			while(hitTimeStamps.size() > 0 &&
				currTimeStamp - hitTimeStamps.front() >= 300){
		
				hitTimeStamps.pop();
			}
		}

		void hit(int timeStamp) {
			uninterestedHitRemover(timeStamp);
			hitTimeStamps.push(timeStamp);
		}
		
		int getHits(int timeStamp) {
			uninterestedHitRemover(timeStamp);
			return hitTimeStamps.size();
		}
};