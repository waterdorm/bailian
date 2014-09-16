/*
	#ifdef DEBUG
	#endif
	for (int i = 0; i < FileIndex; i++)
	{
		for ( int j = 0; j < depth; j++)
			printf("|     ");
		printf("*%s\n",File[i]);
	}
	if (index >= size)
		return 0;
	int len;
	int FileIndex;

	char File[MAX][MAX];
	char buf[MAX];
	len = sprintf(buf,"%s",Data+index);
	if ( buf[0] == ']')
	{	
		index = index + len + 1;
		return 0;
	}
	FileIndex = 0;
	while (buf[0] == 'f')
	{
		index = index + len + 1;
		FileIndex++;
		memcpy(File + FileIndex,buf,strlen(buf)+1);
		len = sprintf(buf,"%s",Data+index);

	}
	if ( buf[0] == 'd')
		{
			for ( int j = 0; j <= depth; j++)
				printf("|     ");
			printf("%s\n",buf);
			//printf("*%d\n",depth);
			depth++;
			Tree(Data,index,depth,size);
		}
	//if ( FileIndex > 1)
	//	qsort(File,FileIndex,sizeof(char *),compare);
	for (int i = 0; i < FileIndex; i++)
	{
		for ( int j = 0; j < depth; j++)
			printf("|     ");
		printf("%s\n",File[i]);
	}
	return 0;
*/
		/*
		#ifdef DEBUG
		int n = 0;
		int len = 0;
		while ( index > n)
		{
		 	len = sprintf(buf,"%s",Data+n)+1;
		 	n+=len;
			printf("%s\n",buf);
		}
		#endif
		*/
