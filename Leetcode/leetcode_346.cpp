class MovingAverage {
	private:
		int queueSize, movingAverage;
		queue<int> movingDataStream;
		
	public:
		MovingAverage(int size) {
			queueSize = size;
			movingAverage = 0;
		}
		
		double next(int val) {
			//Deleting if window size exceeds
			if(movingDataStream.size() >= queueSize){
				movingAverage -= movingDataStream.front();
				movingDataStream.pop();
			} 
			
			//Updating average and pushing in to current window(aka queue)
			movingAverage += val;
			movingDataStream.push(val);
			
			return (double)movingAverage/(double)movingDataStream.size();
		}
};