int commonCharacterCount(std::string s1, std::string s2) {
int i=0, j, count = 0, n = s1.length(), m =s2.length(), t;
while(i < n){

	for(j = 0; j < m; j ++){
		if(s1[i] == s2 [j]){
			count ++;
			t = s2[j];
			s2[j] = s2[m];
			//s2[m] = t;
			m --;
			break;
		}
	}
	i ++;
}
return count;
}
