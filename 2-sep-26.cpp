class Solution {
  public:
    int solve(int n, string s) {
        // code here
        vector<int> occ( 26 , 0 );
        int count = n ;
        int res = 0;
        for( char ch : s){
            if(occ[ch - 'A'] == 0 ){
                if(count > 0){
                    occ[ch - 'A']= 1;
                    count -- ;
                    
                }else{
                    occ[ch - 'A']= 2;
                    res ++ ;
                }
                
            }else if(occ[ch - 'A']== 1){
                count++ ;
                occ[ch - 'A'] = 0;
            }
            else occ[ch - 'A'] == 0;
        }
        return res;
        
    }
};

// 1 2 ...  n

