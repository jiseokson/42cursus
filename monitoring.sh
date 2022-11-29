#!/bin/bash

printf '#Architecture: %s\n' "$(uname -a)"

printf '#CPU physical : %d\n' "$(nproc --all)"

printf '#vCPU : %d\n' "$(cat /proc/cpuinfo | grep processor | wc -l)"

free -m | awk '/Mem/ {printf "#Memory Usage: %d/%dMB (%.2f%%)\n", $3, $2, $3 / $2 * 100}'

df -BM -a | awk '/mapper/ {used += $3; avail += $4} END{total = used + avail; printf "#Disk Usage: %d/%dGb (%d%%)\n", used, total / 1024, used / total * 100}'

mpstat | awk '/all/ {printf "#CPU load: %.1f%%\n", 100 - $13}'

who -b | awk '{printf "#Last boot: %s %s\n", $3, $4}'

printf "#LVM use: "
if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ]
then
	echo "yes"
else
	echo "no"
fi

printf "#Connections TCP : %d ESTABLISHED\n" "$(ss -tunpl | grep tcp | wc -l)"

printf "#User log: %d\n" "$(who | wc -l)"

printf "#Network: IP %s (%s)\n" "$(hostname -I)" "$(ip addr | awk '/ether/{print $2}')"

printf "#Sudo : %d cmd\n" "$(journalctl _COMM=sudo | grep COMMAND | wc -l)"
