const tmi = require('tmi.js');
const SerialPort = require('serialport');

const client = new tmi.Client({
	channels: [ 'YourChannelNameonTwitch' ]     // Change to reflect your channel
});

const Readline = require('@serialport/parser-readline');
const port = new SerialPort('COM3', { baudRate: 9600 });
const parser = port.pipe(new Readline({ delimiter: '\n' }));

client.connect();

client.on('message', (channel, tags, message, self) => {
	// "Alca: Hello, World!"
	console.log(`${tags['display-name']}: ${message}`);    
    if (tags['display-name'] == 'DisplayName') { // Set user name to bypass any checks
        if (message == '!feed') {
            port.write('TRIG\n', (err) => {
                if (err) {
                return console.log('Error on write: ', err.message);
                }
                console.log('message written');
            });
        }
    } else {
        if (message == '!feed') {		// Add extra checks for VIP, MOD, etc.
            port.write('TRIG\n', (err) => {
                if (err) {
                return console.log('Error on write: ', err.message);
                }
                console.log('message written');
            });
        }        
    }
});

// Read the port data
port.on("open", () => {
    console.log('serial port open');
});

parser.on('data', data =>{
    console.log('got word from arduino:', data);
});