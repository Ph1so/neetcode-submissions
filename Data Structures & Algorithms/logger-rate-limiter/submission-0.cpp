class Logger {
public:
    unordered_map<string, int> log_map;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!log_map.contains(message))
        {
            log_map[message] = timestamp + 10;
            return true;
        }

        if (log_map[message] <= timestamp)
        {
            log_map[message] = timestamp + 10;
            return true;
        }

        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
