class Logger {

	private:
		unordered_map<string, int> lastOccuranceTimeStamp;
		
	public:
		Logger() {}
		
		bool shouldPrintMessage(int timestamp, string message) {
			if(lastOccuranceTimeStamp.find(message) != lastOccuranceTimeStamp.end()){
				if(timestamp - lastOccuranceTimeStamp[message] < 10))
					return false;
			
			lastOccuranceTimeStamp[message] = timestamp;
			return true;
		}
};