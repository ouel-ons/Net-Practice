Worked examples
Example 1: 192.168.10.77/26
Mask 255.255.255.192; interesting octet = 4th; block = 256 − 192 = 64
Multiples of 64: 0, 64, 128, 192 → 77 sits in the 64 block
Network: 192.168.10.64
Broadcast: 192.168.10.127 (next network .128 − 1)
Usable range: 192.168.10.65 – 192.168.10.126
Hosts: 2⁶ − 2 = 62
Example 2: 172.16.45.200/20
/20 = 255.255.240.0; interesting octet = 3rd; block = 256 − 240 = 16
Multiples of 16 up to 45: 0, 16, 32, 32, 48 → 45 lives in the 32 block
Network: 172.16.32.0
Broadcast: 172.16.47.255 (next network 172.16.48.0 − 1)
Usable range: 172.16.32.1 – 172.16.47.254
Hosts: 2¹² − 2 = 4,094
Example 3: "I need 5 subnets from 192.168.1.0/24"
2ⁿ ≥ 5 → n = 3 (gives 8 subnets)
New prefix: /24 + 3 = /27 (255.255.255.224), block = 32, 30 hosts each
Subnet	Network	Usable range	Broadcast
1	.0	.1 – .30	.31
2	.32	.33 – .62	.63
3	.64	.65 – .94	.95
4	.96	.97 – .126	.127
5	.128	.129 – .158	.159
6–8	.160, .192, .224	(spare)	.191, .223, .255
Example 4: "I need a subnet for 500 hosts"
2ʰ − 2 ≥ 500 → h = 9 (510 usable)
Prefix = 32 − 9 = /23 → mask 255.255.254.0
Block in 3rd octet = 256 − 254 = 2. So 10.0.4.0/23 covers 10.0.4.0 – 10.0.5.255.
Example 5: Same subnet or not?

Are 10.1.1.200/25 and 10.1.1.50/25 in the same subnet?

/25 → block 128 → subnets are .0–.127 and .128–.255
.50 is in the first; .200 is in the second → different subnets, so they need a router to communicate.
