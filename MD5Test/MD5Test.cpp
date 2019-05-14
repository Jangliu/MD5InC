#include "pch.h"
#include "md5_2.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	unsigned char encrypt[] = "admin";//21232f297a57a5a743894a0e4a801fc3
	unsigned char decrypt[16];
	char encrypt1[2048];
	FILE*Fid;
	errno_t err;
	err = fopen_s(&Fid, "a.txt", "ab+");
	fread_s(encrypt1, 2048, 1, 2048, Fid);
	MD5_CTX md5;
	MD5Init(&md5);
	MD5Update(&md5, (unsigned char*)encrypt1, strlen((char *)encrypt));
	MD5Final(&md5, decrypt);
	printf("加密前:%s\n加密后:", encrypt);
	for (i = 0; i < 16; i++)
	{
		printf("%02x", decrypt[i]);
	}

	getchar();

	return 0;
}
