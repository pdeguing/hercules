# Launch Debian container with docker
docker run --rm -it debian

# Install ssh
apt-get install -y ssh

# Change the ssh port by default
echo "Port 49153" >> /etc/ssh/sshd_config

# Restart for change to set in
/etc/init.d/ssh restart

# And check if port is listening (adjust user@host before using)
ssh root@7e60d4a77251 -p 49153
