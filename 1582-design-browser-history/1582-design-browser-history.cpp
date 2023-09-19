class BrowserHistory {
public:

    list<string>history;
    list<string>::iterator it;

    BrowserHistory(string homepage) {
        // history.push_back(homepage);
        // it++;
        it = history.insert(history.end(), homepage);
    }
    
    void visit(string url) {
        list<string> :: iterator del = it;
        del++;
        history.erase(del, history.end());
        history.push_back(url);
        it++;
        // if(!history.empty()){
        //     if(history.end() == it)
        //     return;

        //     if(it != history.end()){
        //         ++it;
        //         history.erase(it, history.end());
        //     }
        // }
        // it = history.insert(history.end(), url);
    }
    
    string back(int steps) {
        while((it != history.begin() && steps--)){
            it--;
        }
        return *it;
        // while(steps--){
        //     if(*it == history.front())
        //         return history.front();
        //     it--;
        // }
        // return *it;
    }
    
    string forward(int steps) {
        while((it != (--history.end()) && steps--)){
            it++;
        }
        return *it;
        // while(steps--){
        //     if(*it == history.back())
        //         return history.back();
        //     it++;
        // }
        // return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */