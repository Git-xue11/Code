void next() /// 处理模式串的next数组
{
	int i , j ; i = 0 , j = nx[0] = -1 ;
	while(i<m){
		while(j!=-1 && sub[i]!=sub[j]) j = nx[j] ;
		if(sub[++i] == sub[++j]) nx[i] =nx[j] ;
		else nx[i] = j ;
	}
}
int KMP() /// 是否包含 sub 串
{
	int i = 0 , j = 0 ;
	while(i<n && j<m){
		if(str[i]==sub[j] || j==-1) {
			++i , ++j ;
			if(j==m) return i-m+1 ;
		} else j = nx[j] ;
	}
	return -1 ;
}
int kmp_count() /// 计算sub出现次数
{
	int i = 0 , j = 0 , ans = 0 ;
	while(i<n){
		while(j!=-1 && primary[i]!=pattern[j]) j = nx[j] ;
		++i , ++j;
		if(j>=m) ++ans , j = nx[j] ; /// 允许重叠
		/// if(i>=m) ++ans , j = 0 ; /// 不允许重叠
	}
	return ans;
}
int calc() /// 循环节
{
	int m = str.size();
	int len = m - nx[m] ; /// 循环节长度
	if(m%len) cout<<len-m%len<<endl; /// 
	else cout<<(len==m?m:0)<<endl; /// 
}
