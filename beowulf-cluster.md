## Steps - 
1. Install Oracle Virtual Box
2. Set up and install a stable Linux version (I used Ubuntu 16.04.4) in separate virtual machines (prefered 3-4)
3. After installation, power off the virtual machine and do the following in each virtual machine

      Settings -> Network -> Check the "Enable Network Adaptor" option -> Select "Bridged Adaptor" and select the displayed name -> OK
4. Install ssh-server by using `sudo apt-get install openssh-server`
5. Assign a static IP address to each virtual machine by - 
    - Run the following commands in terminal -
        - `ifconfig` -> gives the network name, address, netmask, network address(X.X.0.0) and broadcast address
        - `route -m` ->  gives the gateway address
        - `cat /etc/resolv.conf` -> gives the dns-nameservers address
    - `cd /etc/network` and then open up interfaces using `sudo gedit interfaces`
    - Add the following lines -     
    ```
    auto {insert-network-name}
    iface {insert-network-name} inet static
    address {insert-ip-address}
    netmask {insert-network-mask}
    network {insert-network-address}
    broadcast {insert-broadcast-address}
    gateway {insert-gateway-address}
    dns-nameservers {insert-dns-nameservers-address}
    ```
    - Save the file and restart your network 
6. From home directory, open up hosts file using - 
```
cd /etc
sudo gedit hosts
```
   Add the following info - 
```
{host1 IP address} {host1-name} 
{host2 IP address} {host2-name} 
{host3 IP address} {host3-name} 
.
.
.
```
