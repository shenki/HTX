* This rule files is primarily used by manufacturing
* This combinations of patterns and associated iterations is able to stress
* the memory for a minimum length of time, as required by manufacturing.
* Hxemem waits for 90 seconds before allocating any memory for the test.
* Memory that remains after the OS and other apps have allocated their's,
* is used for the test.
* In this case, 90 percent of remaining memory will be used up.
rule_id = MemTest
pattern_id = HEXFF(8) HEXZEROS(8) 0xAAAA5555AAAA5555 0x5555AAAA5555AAAA 0xCCCCCCCCCCCCCCCC 0x3333333333333333 0x0F0F0F0F0F0F0F0F 0x3C3C3C3C3C3C3C3C 0x5A5A5A5A5A5A5A5A
max_mem = yes
mem_percent = 90
compare = yes
num_oper = 500
num_writes = 1
num_read_only = 1
num_read_comp = 1
switch_pat_per_seg = all
mode = concurrent
bind_proc = yes
oper = mem
width = 8

