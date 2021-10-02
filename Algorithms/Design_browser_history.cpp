//1472. Design Browser History (Leetcode)

/*You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.*/




class BrowserHistory {
public:
    
    

    
    stack<string>st;
    stack<string>fs;
    BrowserHistory(string homepage) {
        st.push(homepage);
    }
    
    void visit(string url) {
        st.push(url);
        while(!fs.empty())
        {
            fs.pop();
        }
    }
    
    string back(int steps) {
        int j=0;
        string curr;
        while(j<steps&&st.size()>1)
        {
         curr=st.top();
            st.pop();
                        fs.push(curr);

            j++;
        }
        return st.top();
    }
    
    string forward(int steps) {
        
        int j=0; string nn;
        while(j<steps&&!fs.empty())
        {
             string nn=fs.top();
            fs.pop();
            st.push(nn);
            j++;
        }
        return st.top(); 
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
 
