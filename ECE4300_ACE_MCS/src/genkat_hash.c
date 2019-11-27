//
// NIST-developed software is provided by NIST as a public service.
// You may use, copy and distribute copies of the software in any medium,
// provided that you keep intact this entire notice. You may improve, 
// modify and create derivative works of the software or any portion of
// the software, and you may copy and distribute such modifications or
// works. Modified works should carry a notice stating that you changed
// the software and should note the date and nature of any such change.
// Please explicitly acknowledge the National Institute of Standards and 
// Technology as the source of the software.
//
// NIST-developed software is expressly provided "AS IS." NIST MAKES NO 
// WARRANTY OF ANY KIND, EXPRESS, IMPLIED, IN FACT OR ARISING BY OPERATION
// OF LAW, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT AND DATA ACCURACY. NIST
// NEITHER REPRESENTS NOR WARRANTS THAT THE OPERATION OF THE SOFTWARE WILL BE 
// UNINTERRUPTED OR ERROR-FREE, OR THAT ANY DEFECTS WILL BE CORRECTED. NIST 
// DOES NOT WARRANT OR MAKE ANY REPRESENTATIONS REGARDING THE USE OF THE SOFTWARE
// OR THE RESULTS THEREOF, INCLUDING BUT NOT LIMITED TO THE CORRECTNESS, ACCURACY,
// RELIABILITY, OR USEFULNESS OF THE SOFTWARE.
//
// You are solely responsible for determining the appropriateness of using and 
// distributing the software and you assume all risks associated with its use, 
// including but not limited to the risks and costs of program errors, compliance 
// with applicable laws, damage to or loss of data, programs or equipment, and 
// the unavailability or interruption of operation. This software is not intended
// to be used in any situation where a failure could cause risk of injury or 
// damage to property. The software developed by NIST employees is not subject to
// copyright protection within the United States.
//

//ECE4300 ACE Crypto Hash test
//Adapted for use in ECE4300 by Alex Willard
//All rights to the ACE team for development of the vast majority of this code


//Needed for running on our microblaze system
#include "chu_init.h"

#include <stdio.h>
#include <string.h>

#include "crypto_hash.h"
#include "api.h"

#define KAT_SUCCESS          0
#define KAT_FILE_OPEN_ERROR -1
#define KAT_DATA_ERROR      -3
#define KAT_CRYPTO_FAILURE  -4

#define MAX_FILE_NAME				256
//#define MAX_MESSAGE_LENGTH			256
int MAX_MESSAGE_LENGTH = 256;
//int max_msg_lengths[] = {64, 128, 256};
void init_buffer(unsigned char *buffer, unsigned long long numbytes);

void fprint_bstr(FILE *fp, const char *label, const unsigned char *data, unsigned long long length);

int generate_test_vectors();


int main()
{
	for(int i = 0; i < 257; i++)
	{
		MAX_MESSAGE_LENGTH = i;
		uart.disp("Starting test for m_MAX = ");
		uart.disp(MAX_MESSAGE_LENGTH);
		uart.disp("\n\r");
		unsigned long start = now_ms();//get start time for our test


		int ret = generate_test_vectors();


		if (ret != KAT_SUCCESS) {

			uart.disp("FAILURE\n\r");
		}
		//get ending time for our test
		unsigned long time = now_ms() - start;
		int time_int = (int)time;
		uart.disp(time_int);
		uart.disp(", ");


	}
	unsigned long start = now_ms();//get start time for our test


	int ret = generate_test_vectors();

	return 0;
}

int generate_test_vectors()
{
	//FILE                *fp;
	//char                fileName[MAX_FILE_NAME];
	unsigned char       msg[MAX_MESSAGE_LENGTH];
	unsigned char		digest[CRYPTO_BYTES];
	int                 ret_val = KAT_SUCCESS;
	//int					count = 1;

	init_buffer(msg, sizeof(msg));
	/*
	sprintf(fileName, "../LWC_HASH_KAT_%d.txt", (CRYPTO_BYTES * 8));


	if ((fp = fopen(fileName, "w")) == NULL) {
		fprintf(stderr, "Couldn't open <%s> for write\n", fileName);
		return KAT_FILE_OPEN_ERROR;
	}
	*/

	//The original code uses a for loop to go through max message lengths, we decided to just generate one test vector

	/*
	for (unsigned long long mlen = 0; mlen <= MAX_MESSAGE_LENGTH; mlen++) {

		//fprintf(fp, "Count = %d\n", count++);

		//fprint_bstr(fp, "Msg = ", msg, mlen);

		ret_val = crypto_hash(digest, msg, mlen);
		
		if(ret_val != 0) {
			//fprintf(fp, "crypto_hash returned <%d>\n", ret_val);
			ret_val = KAT_CRYPTO_FAILURE;
			break;
		}

		//fprint_bstr(fp, "MD = ", digest, CRYPTO_BYTES);

		//fprintf(fp, "\n");
	}
*/

	ret_val = crypto_hash(digest, msg, MAX_MESSAGE_LENGTH);

	//fclose(fp);

	return ret_val;
}
/*
void fprint_bstr(FILE *fp, const char *label, const unsigned char *data, unsigned long long length)
{    
    fprintf(fp, "%s", label);
        
	for (unsigned long long i = 0; i < length; i++)
		fprintf(fp, "%02X", data[i]);
	    
    fprintf(fp, "\n");
}
*/
void init_buffer(unsigned char *buffer, unsigned long long numbytes)
{
	for (unsigned long long i = 0; i < numbytes; i++)
		buffer[i] = (unsigned char)i;
}
