// Copyright 2024 binoll
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

#include <linux/blkpg.h>
#include <linux/magic.h>
#include <linux/fs.h>

#include <sys/stat.h>
#include <sys/statfs.h>
#include <sys/statvfs.h>

/*A function to proccessing/get a file to/from an empty place in the cluster*/
int8_t save_file(int32_t, int32_t);

int8_t get_file(int32_t, int32_t);
