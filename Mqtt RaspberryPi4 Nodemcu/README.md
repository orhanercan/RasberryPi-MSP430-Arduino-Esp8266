This Mqtt server created with using mosquitto.For installing mosquitto in Raspberry Pi

Run the following command to upgrade and update your system:

sudo apt update && sudo apt upgrade
 Press Y and Enter. It will take some time to update and upgrade (in my case, it took approximately 10 minutes).

To install the Mosquitto Broker enter these next commands:

sudo apt install -y mosquitto mosquitto-clients

To make Mosquitto auto start when the Raspberry Pi boots, you need to run the following command (this means that the Mosquitto broker will automatically start when the Raspberry Pi starts):

sudo systemctl enable mosquitto.service

 Now, test the installation by running the following command:

mosquitto -v
This returns the Mosquitto version that is currently running in your Raspberry Pi. It will be 2.0.11 or above.

To publish a message to a topic, type the following command:

mosquitto_pub -d -u username -P password -t Test -m "Hello, World!"
Replace username and password with you username and password. In case that step was skipped, simply type the following command:

mosquitto_pub -d -t Test -m "Hello, World!"

![Raspi4](https://user-images.githubusercontent.com/57947304/194847085-6b025c40-529e-470b-872f-4e4e2d656016.jpeg)
![Rpi terminal1](https://user-images.githubusercontent.com/57947304/194847125-b52bf5f7-19d5-4d09-ac3b-1eb758bc9a64.png)
![Rpi terminal2](https://user-images.githubusercontent.com/57947304/194847151-7f80ce78-d491-453a-8561-3b5adfcdec46.png)
![Rpi terminal3](https://user-images.githubusercontent.com/57947304/194847180-c1f8490f-f1b1-4311-bbf4-fb3401409d17.png)
![mqtt explorer](https://user-images.githubusercontent.com/57947304/194847193-10e87ea3-9a88-43ba-b704-c256c03df709.png)
