int search(string pat, string txt) {
	    int res=0;
	    // using unordered_map
	    unordered_map<char,int>m;
	    for(char ch:pat){
	        m[ch]++;
	    }
	    // size of the map
	    int ct=m.size();
	    // size of the window
	    int k=pat.size();
	    int i=0,j=0;
	    // size of the txt
	    int n=txt.size();
	    while(j<n){
	        if(m.find(txt[j])!=m.end()){
	            m[txt[j]]--;
	            if(m[txt[j]]==0){
	                ct--;
	            }
	        }
	        
	        //window size has not been got yet
	        if(j-i+1<k){
	            j++;
	        }
	        // hit the window size
	        else if(j-i+1==k){
	            if(ct==0){
	                res++;
	            }
	            
	            if(m.find(txt[i])!=m.end()){
	                m[txt[i]]++;
	                if(m[txt[i]]==1){
	                    ct++;
	                }
	            }
	                    
	             i++;
	             j++;
	            
	        }
	    }
	    return res;
	    
	}
