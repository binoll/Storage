// Copyright 2024 binoll
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include <linux/blkpg.h>
#include <linux/magic.h>
#include <linux/fs.h>

#include <sys/stat.h>
#include <sys/statfs.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 128
#define MAX_PATH_SIZE 255

int save_file(int, int, off_t, off_t, off_t);

int get_file(int, int, off_t, off_t);
