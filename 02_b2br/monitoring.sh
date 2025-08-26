#!/bin/bash

arch=$(uname -a)
cpuf=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
cpuv=$(grep -c processor /proc/cpuinfo)
ram_total=$(free -m | awk '/Mem:/ {print $2}')
ram_use=$(free -m | awk '/Mem:/ {print $3}')
ram_percent=$(free -m | awk '/Mem:/ {printf("%.2f"), $3/$2*100}')
disk_total=$(df -BM --total | awk '/total/ {print $2}')
disk_use=$(df -BM --total | awk '/total/ {print $3}')
disk_percent=$(df -h --total | awk '/total/ {print $5}')
cpu_load=$(mpstat | awk '/all/ { printf("%.1f\n", 100 - $NF) }')
last_boot=$(who -b | awk '{print $3, $4}')
lvm_use=$(lsblk | grep -q "lvm" && echo yes || echo no)
tcp_conn=$(ss -ta | grep ESTAB | wc -l)
user_log=$(who | wc -l)
ip=$(hostname -I | awk '{print $1}')
mac=$(ip link | awk '/ether/ {print $2; exit}')
sudo_count=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

message="
	#Architecture: $arch
	#CPU physical: $cpuf
	#vCPU: $cpuv
	#Memory Usage: ${ram_use}/${ram_total}MB (${ram_percent}%)
	#Disk Usage: ${disk_use}/${disk_total} (${disk_percent})
	#CPU load: ${cpu_load}%
	#Last boot: ${last_boot}
	#LVM use: ${lvm_use}
	#Connections TCP: ${tcp_conn} ESTABLISHED
	#User log: ${user_log}
	#Network: IP ${ip} (${mac})
	#Sudo: ${sudo_count} cmd
	"

if [ ! -f /tmp/startup-message-displayed ]; then

        echo "$message" | sudo tee /etc/issue > /dev/null
        touch /tmp/startup-message-displayed
fi

ls /dev/pts/* /dev/tty[1-6] | while read -r TTY; do
  if [ -w "$TTY" ]; then
    printf "%s\n" "$message" > "$TTY"
  fi
done
