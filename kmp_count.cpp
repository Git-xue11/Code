void next() /// 处理模式串
{
	int i , j ; i = 0 , j = nx[0] = -1 ;
	while(i<m){
		while(j!=-1 && pattern[i]!=pattern[j]) j = nx[j] ;
		if(pattern[++i] == pattern[++j]) nx[i] =nx[j] ;
		else nx[i] = j ;
	}
}
int KMP()
{
	int i = 0 , j = 0 ;
	while(i<n && j<m){
		if(primary[i]==pattern[j] || j==-1) {
			++i , ++j ;
			if(j==m) return i-m+1 ;
		} else j = nx[j] ;
	}
	return -1 ;
}
int kmp_count()
{
	int i = 0 , j = 0 , ans = 0 ;
	while(i<n){
		while(j!=-1 && primary[i]!=pattern[j]) j = nx[j] ;
		++i , ++j;
		if(j>=m) ++ans , j = nx[j] ;
	}
	return ans;
}
void solve() 
{
	for(cin>>t;t;t--){
		memset(nx,-1,sizeof(nx));
		cin>>pattern>>primary; n = primary.size() , m = pattern.size() ; /// 模式串，主串
		next() ; cout<< KMP() <<endl ;
		//// cout<<kmp_count()<<endl;
	}
}