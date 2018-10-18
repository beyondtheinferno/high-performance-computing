## STEPS TO CREATE A BEOWULF CLUSTER -

*(My Host PC OS - Windows. There shouldn't be much difference in other OS, that's what I hope.)*

1. Install the latest version of Oracle VirtualBox

2. Set up and install a stable Linux version (I used Ubuntu 16.04.4) in separate virtual machines (preferred 3-4)

3. **ENABLE BRIDGED NETWORKING BETWEEN THE NODES**  

      After installation, power off the virtual machines and for each node, do -

      *Settings -> Network -> Check the "Enable Network Adaptor" option -> Select "Bridged Adaptor" and select any one of the options that works-> OK*

4. Make sure all the nodes have the same username. If they have different usernames, create a new user in all nodes with a common name and give sudo permissions to the new users. Install *ssh-server* on the master node and all the slave nodes by using `sudo apt-get install openssh-server`

5. **STATIC IP ALLOCATION** 

    Assign a static IP address to node by - 

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

6. From home directory, open up hosts file in each node using - 
```bash
cd /etc
sudo gedit hosts
```

Add the following info in all the nodes - 
```
{host1 IP address} {master-node-name} 
{host2 IP address} {slave1-node-name} 
{host3 IP address} {slave2-node-name} 
.
.
.
```

7. **CREATE PASSWORDLESS SSH FOR LOG IN FROM master node TO slave nodes**

**METHOD 1**
   * On the all the node, type `ssh-keygen` on the terminal. Just hit enter for all other options. This option will create a *id_rsa.pub* RSA public key for your node.
   * On the master node, type `ssh-copy-id -i  ~/.ssh/id_rsa.pub <first-node-name>` on the terminal. It will prompt you for the password of the *first-node*, enter that. Repeat this step for all nodes. This will copy your RSA public key of your master node to the *id_rsa.pub* of your other nodes, enabling a passwordless SSH from master to all the slave node.
   * To check if this works, try `ssh <node-name>`. Try out for all nodes.
   * Note - Passwordless log in from slave to master is not possible with these steps and we won‘t be requiring that.

**METHOD 2**
   * On the master node, run the command `ssh-keygen -t rsa`

   * On the master node, do the following for slave node 1 - 

     ```bash
     ssh <username>@<slave-node1-name> mkdir -p .ssh
     cat .ssh/id_rsa.pub | ssh <username>@<slave-node1-name> 'cat >> .ssh/authorized_keys'
     ssh <username>@<slave-node1-name> "chmod 700 .ssh; chmod 640 .ssh/authorized_keys"
     ```

* Run `ssh <slave-node1-name>` and see if you can ssh without any password
* Repeat the steps for all other slave nodes, excluding step 1 of METHOD 2. The ssh-keygen for master node needs to be done only once.

8. **SETTING UP NFS SERVER AND CLIENTS**

* **NFS -** Network File System. Used to view, store and update files between local and remote systems. Here, we’ll use it to provide a shared memory to the master and slave nodes.

* **On the master node**, run the command `sudo apt-get install nfs-kernel-server` and install the NFS server. Create the folder that will be shared among the master and slave nodes using `mkdir <foldername>` .  Move to etc folders and open up the exports file using `cd /etc` and `sudo gedit exports` . Add the following at the end - 

  ```
  /home/<username>/<foldername> <slave-node1-name>(rw,sync,no_root_squash,no_subtree_check)
  /home/<username>/<foldername> <slave-node2-name>(rw,sync,no_root_squash,no_subtree_check)
  .
  .
  .
  ```

* Go back to home directory, run `exportfs -a` in the terminal followed by `sudo service nfs-kernel-server restart`

* **On the slave nodes**, run the command `sudo apt-get install nfs-common`. Create a file with the same name as the one on the master node `<foldername>`. Run `sudo mount -t nfs <master-node-name>:/home/<username>/<foldername> ~/<foldername>`. To check if it’s mounted or not, run `df -h`. To permanently mount it, go to */etc* folder and open up *fstab* file using `cd /etc` and `sudo gedit fstab`. Add the following at the end -  

  ```
  <master-node-name>:/home/<username>/<foldername> /home/<username>/<foldername>
  ```

9. **INSTALLING MPI ON ALL THE NODES**

- **NOTE - **MAKE SURE YOU INSTALL THE SAME VERSION OF MPI ON ALL NODES
- Download the latest stable version of MPI tar file from [here](www.mpich.org). 
- Extract the tar using `tar -xzf <mpich-tar-filename>`
- Go to the extracted file
- Run `./configure --disable-fortran`
- Run the command `make`
- Run the command `sudo make install`
- Check if build was successful using `mpiexec --version`

10. **RUNNING A SAMPLE MPI PROGRAM IN THE CLUSTER**

* We’ll just test our cluster and hence use an existing code that has already been compiled into an executable file in the examples file of MPI folder.
* **On the master node - **Go to the MPI folder on home -> examples -> copy the *cpi* executable and paste it in the shared folder.

* Navigate to the shared folder through the terminal and run `mpi -np <> -hosts <slave1-node-name>,<slave2-node-name> ./cpi`

And that’s it. We’ve formed a Beowulf cluster and allocated different tasks to each slave node from the master node via a shared memory. :)