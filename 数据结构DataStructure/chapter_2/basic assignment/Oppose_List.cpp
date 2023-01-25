//Ë³Ğò±í¾ÍµØÄæÖÃ



int Oppose_List(int list[], int length ){
	int tem;
	for(int i=0; i<length/2; i++){
		tem = list[i];
		list[i] = list[length-i-1];
		list[length-i-1] = tem;
	}
	
	return 1;
}