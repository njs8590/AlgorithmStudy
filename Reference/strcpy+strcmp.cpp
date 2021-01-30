void m_strcpy(char *from, char *to) {
	int i = 0;
	while (from[i]) {
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}

int m_strcmp(char *str1, char *str2) {	//´Ù¸£¸é 1
	int i = 0;
	while (str1[i]) {
		if (str2[i] != str1[i]) {
			return 1;
		}
		i++;
	}
	if (str2[i] != '\0')
		return 1;
	return 0;
}