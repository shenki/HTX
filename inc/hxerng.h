/* IBM_PROLOG_BEGIN_TAG */
/* 
 * Copyright 2003,2016 IBM International Business Machines Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 		 http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/* IBM_PROLOG_END_TAG */
/* @(#)66	1.3  src/htx/usr/lpp/htx/bin/hxerng/hxerng.h, exer_rng, htx61Q 3/9/11 00:36:42 */

#ifndef _HXERNG_H_
#define _HXERNG_H_

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>

#ifndef __HTX_LINUX__
#include <sys/systemcfg.h>
#include "hcall.h"
#endif

/* HTX related header files */
#include <hxihtx64.h>

/* Random testing function related header files */
#include "test_utils.h"

#ifdef __HTX_LINUX__
#else
#endif

struct dev_info {
	char device_name[50];
	char run_type[4];
	char rule_file_name[200];
} dinfo;

#define		TRUE		1
#define		FALSE		0

#define		NUM_TESTS	15
#define		EXTRA_THS	2

#ifdef DEBUG
#define DPRINT fprintf
#define FFLUSH fflush
#else
#define DPRINT
#define FFLUSH
#endif

/* Definition of all types of tests */
#define		READ_RNO							0
#define		FREQUENCY							1
#define		BLOCK_FREQUENCY						2
#define		RUNS								3
#define		LONGEST_RUN_OF_ONES					4
#define		MATRIX_RANK							5
#define		DISCRETE_FOURIER_TRANSFORM			6
#define		NON_OVERLAPPING_TEMPLATE_MATCHING	7
#define		OVERLAPPING_TEMPLATE_MATCHING		8
#define		UNIVERSAL							9
#define		APPROXIMATE_ENTROPY					10
#define		CUMULATIVE_SUM						11
#define		RANDOM_EXCURSIONS					12
#define		RANDOM_EXCURSIONS_VARIANT			13
#define		SERIAL								14
#define		LINEAR_COMPLEXITY					15

/* Shared seg key */
#define		BIT_SHM_KEY			0x10010000
#define		BYTE_SHM_KEY		0x10020000


/* Random number stream size */
#define		STREAM_SIZE			1048576
#define		MAX_SLOTS			64

/* Maximum number of rules supported */
#define 	MAX_NUM_RULES		10
#define		MAX_RULE_LINE_SIZE	150

/* Rule file parameters */
struct rule_parameters {
	char rule_name[20];
	int stream_len;
	int blockFrequency_block_len;
	int nonOverlappingTemplate_block_len;
	int overlappingTemplate_block_len;
	int approxEntropy_block_len;
	int serial_block_len;
	int linearComplexity_sequence_len;
	int tests_to_run[NUM_TESTS];
	int num_oper;
};

/* function pointer for all the client functions */
typedef int (*worker)(void *);

void sigterm_hdl(void);
void sigusr1_hdl(void);
void sigreconfig_hdl(void);
void clean_up(void);
int check_rng_available(void);
int allocate_mem(void);
int read_rf(void);
int parse_line(char *);
int get_line( char *, int, FILE *, char, int *);
int get_rule(int *, FILE *, struct rule_parameters *);
int get_PVR(void);
unsigned long getPvr(void);


unsigned long long read_rn(void);
int read_rn_func(void *);
int convert_bit_2_byte(void *);
#ifdef __HTX_OPEN_SOURCE__
int freq(void *);
int block_freq(void *);
int runs(void *);
int longest_run_of_ones(void *);
int rank(void *);
int dft(void *);
int non_overlapping_tm(void *);
int overlapping_tm(void *);
int universal(void *);
int approx_entropy(void *);
int cusum(void *);
int random_excursion(void *);
int random_excursion_var(void *);
int serial(void *);
int linear_complexity(void *);
#endif
int h_cop_random_k(caddr_t *, caddr_t *);

/* Global string to print messages */
char msg[1000];

#endif /* _HXERNG_H_ */
