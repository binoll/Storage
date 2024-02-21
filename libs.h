#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <linux/fs.h>

char saving[] = {
		'/',
		'-',
		'\\',
		'|'
};

/*A function to save/get a file to/from an empty place in the cluster*/
__stdcall int8_t save_file(int64_t, int64_t);

__stdcall int8_t get_file(int64_t, int64_t);
