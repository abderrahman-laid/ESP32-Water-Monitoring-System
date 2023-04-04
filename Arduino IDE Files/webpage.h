//webpage.h
//=====================
//HTML,CSS,JSP code for webpage
//=====================
const char webpageCont[] PROGMEM = 
R"=====(
<!DOCTYPE HTML>
<html>
<title>ESP32 Water Monitoring System</title>
<link href='https://fonts.googleapis.com/css?family=Roboto' rel='stylesheet'>
<!---------------------------CSS-------------------------->
<style>
    	body {
			background-color: #e8e8e8;
		}
		.newtons-cradle {
    --uib-size: 70px;
    --uib-speed: 1.2s;
    --uib-color: #5C8EEE;
    position: fixed;
    bottom: 40%;
    right: 48.5%;
    display: flex;
    align-items: center;
    justify-content: center;
    width: var(--uib-size);
    height: var(--uib-size);
                        }
        .newtons-cradle__dot {
    position: relative;
    display: flex;
    align-items: center;
    height: 100%;
    width: 25%;
    transform-origin: center top;
                             }
        .newtons-cradle__dot::after {
    content: '';
    display: block;
    width: 100%;
    height: 25%;
    border-radius: 50%;
    background-color: var(--uib-color);
                                    }
        .newtons-cradle__dot:first-child {
    animation: swing var(--uib-speed) linear infinite;
                                         }
        .newtons-cradle__dot:last-child {
    animation: swing2 var(--uib-speed) linear infinite;
                                        }
        @keyframes swing  {
    0%                   {
  transform: rotate(0deg);
  animation-timing-function: ease-out;
 }

    25%                  {
    transform: rotate(70deg);
    animation-timing-function: ease-in;
        }

    50%                  {
  transform: rotate(0deg);
  animation-timing-function: linear;
                             }
                         }
        @keyframes swing2 {
    0%                   {
    transform: rotate(0deg);
    animation-timing-function: linear;
                             }

    50%                  {
  transform: rotate(0deg);
  animation-timing-function: ease-out;
                            }

    75%                  {
  transform: rotate(-70deg);
  animation-timing-function: ease-in;
                             }
                          }
		tank {
            width: 300px;
			height: 550px;
			background: linear-gradient(90deg, #E6E6FA 0%, #e0e0e0 50%, #D3D3D3 100%) center no-repeat;
			box-shadow: 15px 15px 30px #bebebe,
             -15px -15px 30px #ffffff;
			border-radius: 10px 10px 20px 20px;
			position: fixed;
            bottom: 4%;
            right: 40%;
		}
		tank #water {
		    width: 300px;
			height:0%;
      transition: height 0.5s ease-out;
			background: linear-gradient(90deg, rgba(92, 142, 238, 0.51) 0%, #5C8EEE 100%);
			border-radius: 10px 10px 20px 20px;
			border-radius: 10px 10px 20px 20px;
			position: absolute;
            bottom: 0%;
            right: 0%;
		}
		#box_switch {
            width: 300px;
			height: 300px;
			background: linear-gradient(90deg, #E6E6FA 0%, #e0e0e0 50%, #D3D3D3 100%) center no-repeat;
			box-shadow: 15px 15px 30px #bebebe,
             -15px -15px 30px #ffffff;
             border: 2px solid #5C8EEE;
			border-radius: 30px ;
			position: fixed;
            bottom: 35%;
            right: 8%;
		}
		button_doc {
        color: #090909;
        padding: 0.7em 1.7em;
        font-family: inherit;
        font-weight: 500;
        font-size: 18px;
        border-radius: 0.8em;
        letter-spacing: 0.05em;
        background: #e8e8e8;
        border: 1px solid #e8e8e8;
        transition: all .3s;
        box-shadow: 6px 6px 12px #c5c5c5,
             -6px -6px 12px #ffffff;
             position: fixed;
            bottom: 3%;
            right: 2%;
        }
        button_doc:hover {
         border: 1px solid #5C8EEE;
        }
        button_doc:active {
        box-shadow: 4px 4px 12px #c5c5c5,
             -4px -4px 12px #ffffff;}
        #documentation_text {
			color: black; 
			text-decoration: none;
			font-family: Arial, sans-serif;
			color:#5C8EEE;
			text-shadow: 1px 2px 6px #969696;
		}
		button_code {
        color: #090909;
        padding: 0.7em 1.7em;
        font-family: inherit;
        font-weight: 500;
        font-size: 18px;
        letter-spacing: 0.05em;
        border-radius: 0.8em;
        background: #e8e8e8;
        border: 1px solid #e8e8e8;
        transition: all .3s;
        box-shadow: 6px 6px 12px #c5c5c5,
             -6px -6px 12px #ffffff;
             position: fixed;
            bottom: 2.8%;
            right: 19%;
        }
        button_code:hover {
         border: 1px solid #5C8EEE;}
        button_code:active {
        box-shadow: 4px 4px 12px #c5c5c5,
             -4px -4px 12px #ffffff;}
    	#code_text {
			color: black; 
			text-decoration: none;
			font-family: Arial, sans-serif;
			color:#5C8EEE;
			text-shadow: 1px 2px 6px #969696;
		}
        svg {
        position: fixed;
        bottom: 5%;
        right: 3.1%;
        }
        .switch {
            font-size: 30px;
            position: fixed;
            bottom: 50%;
            right: 15%;
            display: inline-block;
            width: 3.5em;
            height: 2em;
                }
        .switch input {
            opacity: 0;
            width: 0;
            height: 0;
                }
        .slider {
            position: absolute;
            cursor: pointer;
            top: 0;
            left: 0;
            right: 0;
            bottom: 0;
            background: linear-gradient(90deg, #E6E6FA 0%, #e0e0e0 50%, #D3D3D3 100%) center no-repeat;
            box-shadow: 5px 10px 30px #bebebe,
             -5px -10px 30px #ffffff;
            transition: .4s;
            border: 1px solid #5C8EEE;
            border-radius: 10px;
                }
        .slider:before {
            position: absolute;
            content: "";
            height: 1.4em;
            width: 0.1em;
            border-radius: 0px;
            left: 0.3em;
            bottom: 0.3em;
            background-color: white;
            transition: .4s;
                        }
        input:checked + .slider {
            background: linear-gradient(90deg, rgba(92, 142, 238, 0.51) 0%, #5C8EEE 100%);
                        }
        input:checked + .slider:before {
            transform: translateX(2.8em) ;
            background-color: var(green);
                        }
        #switch_text{
            font-family: 'Verdana';
            font-family: 'Roboto';
            color: #205FDA;
		    text-shadow: 5px 3px 6px rgba(0, 0, 0, 0.3);
			font-weight: 500;
			font-size: 20px;
			margin: 0;
			text-align: center;
			position: absolute;
			top: 30%;
			left: 81%;
			transform: translate(-50%, -50%);
        }
        #copyright {
        font-size: 12px;
        position:fixed;
        bottom:-2%;
        left:0.1%;
		}
        #capacity {
            font-family: 'Segoe UI';
            font-family: 'Roboto';
            color: #205FDA;
		    -webkit-text-stroke-width: 1.5px;
            -webkit-text-stroke-color: #E0E0E0;
			font-weight: 700;
			font-size: 32px;
			margin: 0;
			text-align: center;
			position: absolute;
			top: 50%;
			left: 49%;
			transform: translate(-50%, -50%);
        }
        #percentage {
            font-family: 'Segoe UI';
            font-family: 'Roboto';
            color: #205FDA;
		    -webkit-text-stroke-width: 1.5px;
            -webkit-text-stroke-color: #E0E0E0;
			font-weight: 700;
			font-size: 27px;
			margin: 0;
            text-align: center;
			position: absolute;
			top: 56%;
			left: 49%;
			transform: translate(-50%, -50%);
        }
    	body {
			background-color: #e8e8e8;
		}
		.newtons-cradle {
    --uib-size: 70px;
    --uib-speed: 1.2s;
    --uib-color: #5C8EEE;
    position: fixed;
    bottom: 40%;
    right: 48.5%;
    display: flex;
    align-items: center;
    justify-content: center;
    width: var(--uib-size);
    height: var(--uib-size);
                        }
        .newtons-cradle__dot {
    position: relative;
    display: flex;
    align-items: center;
    height: 100%;
    width: 25%;
    transform-origin: center top;
                             }
        .newtons-cradle__dot::after {
    content: '';
    display: block;
    width: 100%;
    height: 25%;
    border-radius: 50%;
    background-color: var(--uib-color);
                                    }
        .newtons-cradle__dot:first-child {
    animation: swing var(--uib-speed) linear infinite;
                                         }
        .newtons-cradle__dot:last-child {
    animation: swing2 var(--uib-speed) linear infinite;
                                        }
        @keyframes swing  {
    0%                   {
  transform: rotate(0deg);
  animation-timing-function: ease-out;
 }

    25%                  {
    transform: rotate(70deg);
    animation-timing-function: ease-in;
        }

    50%                  {
  transform: rotate(0deg);
  animation-timing-function: linear;
                             }
                         }
        @keyframes swing2 {
    0%                   {
    transform: rotate(0deg);
    animation-timing-function: linear;
                             }

    50%                  {
  transform: rotate(0deg);
  animation-timing-function: ease-out;
                            }

    75%                  {
  transform: rotate(-70deg);
  animation-timing-function: ease-in;
                             }
                          }
		tank {
            width: 300px;
			height: 550px;
			background: linear-gradient(90deg, #E6E6FA 0%, #e0e0e0 50%, #D3D3D3 100%) center no-repeat;
			box-shadow: 15px 15px 30px #bebebe,
             -15px -15px 30px #ffffff;
			border-radius: 10px 10px 20px 20px;
			position: fixed;
            bottom: 4%;
            right: 40%;
		}
		tank #water {
		    width: 300px;
			height:0%;
      transition: height 0.5s ease-out;
			background: linear-gradient(90deg, rgba(92, 142, 238, 0.51) 0%, #5C8EEE 100%);
			border-radius: 10px 10px 20px 20px;
			border-radius: 10px 10px 20px 20px;
			position: absolute;
            bottom: 0%;
            right: 0%;
		}
		#box_switch {
            width: 300px;
			height: 300px;
			background: linear-gradient(90deg, #E6E6FA 0%, #e0e0e0 50%, #D3D3D3 100%) center no-repeat;
			box-shadow: 15px 15px 30px #bebebe,
             -15px -15px 30px #ffffff;
             border: 2px solid #5C8EEE;
			border-radius: 30px ;
			position: fixed;
            bottom: 35%;
            right: 8%;
		}
		button_doc {
        color: #090909;
        padding: 0.7em 1.7em;
        font-family: inherit;
        font-weight: 500;
        font-size: 18px;
        border-radius: 0.8em;
        letter-spacing: 0.05em;
        background: #e8e8e8;
        border: 1px solid #e8e8e8;
        transition: all .3s;
        box-shadow: 6px 6px 12px #c5c5c5,
             -6px -6px 12px #ffffff;
             position: fixed;
            bottom: 3%;
            right: 2%;
        }
        button_doc:hover {
         border: 1px solid #5C8EEE;
        }
        button_doc:active {
        box-shadow: 4px 4px 12px #c5c5c5,
             -4px -4px 12px #ffffff;}
        #documentation_text {
			color: black; 
			text-decoration: none;
			font-family: Arial, sans-serif;
			color:#5C8EEE;
			text-shadow: 1px 2px 6px #969696;
		}
		button_code {
        color: #090909;
        padding: 0.7em 1.7em;
        font-family: inherit;
        font-weight: 500;
        font-size: 18px;
        letter-spacing: 0.05em;
        border-radius: 0.8em;
        background: #e8e8e8;
        border: 1px solid #e8e8e8;
        transition: all .3s;
        box-shadow: 6px 6px 12px #c5c5c5,
             -6px -6px 12px #ffffff;
             position: fixed;
            bottom: 2.8%;
            right: 19%;
        }
        button_code:hover {
         border: 1px solid #5C8EEE;}
        button_code:active {
        box-shadow: 4px 4px 12px #c5c5c5,
             -4px -4px 12px #ffffff;}
    	#code_text {
			color: black; 
			text-decoration: none;
			font-family: Arial, sans-serif;
			color:#5C8EEE;
			text-shadow: 1px 2px 6px #969696;
		}
        svg {
        position: fixed;
        bottom: 5%;
        right: 3.1%;
        }
        .switch {
            font-size: 30px;
            position: fixed;
            bottom: 50%;
            right: 15%;
            display: inline-block;
            width: 3.5em;
            height: 2em;
                }
        .switch input {
            opacity: 0;
            width: 0;
            height: 0;
                }
        .slider {
            position: absolute;
            cursor: pointer;
            top: 0;
            left: 0;
            right: 0;
            bottom: 0;
            background: linear-gradient(90deg, #E6E6FA 0%, #e0e0e0 50%, #D3D3D3 100%) center no-repeat;
            box-shadow: 5px 10px 30px #bebebe,
             -5px -10px 30px #ffffff;
            transition: .4s;
            border: 1px solid #5C8EEE;
            border-radius: 10px;
                }
        .slider:before {
            position: absolute;
            content: "";
            height: 1.4em;
            width: 0.1em;
            border-radius: 0px;
            left: 0.3em;
            bottom: 0.3em;
            background-color: white;
            transition: .4s;
                        }
        input:checked + .slider {
            background: linear-gradient(90deg, rgba(92, 142, 238, 0.51) 0%, #5C8EEE 100%);
                        }
        input:checked + .slider:before {
            transform: translateX(2.8em) ;
            background-color: var(green);
                        }
        #switch_text{
            font-family: 'Verdana';
            font-style: sans-serif;
            color: #205FDA;
		    text-shadow: 5px 3px 6px rgba(0, 0, 0, 0.3);
			font-weight: 500;
			font-size: 20px;
			margin: 0;
			text-align: center;
			position: absolute;
			top: 30%;
			left: 81%;
			transform: translate(-50%, -50%);
        }
        #copyright {
        font-size: 12px;
        position:fixed;
        bottom:-2%;
        left:0.1%;
		}
        #capacity {
            font-family: 'Segoe UI';
            color: #0C5BF3;
		    -webkit-text-stroke-width: 1.5px;
            -webkit-text-stroke-color: #E0E0E0;
			font-weight: 700;
			font-size: 32px;
			margin: 0;
			text-align: center;
			position: absolute;
			top: 50%;
			left: 49%;
			transform: translate(-50%, -50%);
        }
        #percentage {
            font-family: 'Segoe UI';
            color: #0C5BF3;
		    -webkit-text-stroke-width: 1.5px;
            -webkit-text-stroke-color: #E0E0E0;
			font-weight: 700;
			font-size: 27px;
			margin: 0;
            text-align: center;
			position: absolute;
			top: 56%;
			left: 49%;
			transform: translate(-50%, -50%);
        }
      #title_of_page{
            font-family: 'Segoe UI';
            color: #0C5BF3;
        }
</style>
<!--------------------------HTML-------------------------->
<body>
  <h1 id="title_of_page">ESP32 Water Monitoring System</h1>
  <p id="copyright">&#169 2023 Blida . All Rights Reserved</p>
	<tank>
	<div id="water"></div>
	</tank>
	<div id="box_switch"></div>
	<p id="switch_text">initializing ...</p>
	<p id="capacity"></p>
	<p id="percentage"></p>
	<button_doc><a id=documentation_text href="https://github.com/abderrahman-laid/ESP32-Water-Monitoring-System" target="_blank">Documentation&nbsp;&nbsp;&nbsp;&nbsp;</a></button_doc>
	<button_code><a id=code_text href="https://gist.github.com/abderrahman-laid/691fe1883d8dc185190c1928ff5c9eb2" target="_blank">&lt;/&gt; Code</a></button_code>
	<label class="switch">
  <input type="checkbox" id="FANbtn" onclick="fanONOFF()">
  <span class="slider"></span>
        </label>
  <div class="newtons-cradle" id="loading_animation">
  <div class="newtons-cradle__dot"></div>
  <div class="newtons-cradle__dot"></div>
  <div class="newtons-cradle__dot"></div>
  <div class="newtons-cradle__dot"></div>
  </div>
  <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24"><path fill="#5C8EEE" d="M12 0a12 12 0 0 0-3.8 23.4c.6.1.8-.3.8-.6v-2.2c-3.3.7-4-1.4-4-1.4-.6-1.4-1.4-1.8-1.4-1.8-1-.7.1-.7.1-.7 1.2 0 1.9 1.2 1.9 1.2 1 1.8 2.8 1.3 3.4 1 .2-.8.5-1.3.8-1.6-2.7-.3-5.5-1.3-5.5-6 0-1.2.5-2.3 1.3-3.1-.1-.4-.6-1.6.1-3.2 0 0 1-.3 3.3 1.2a11.5 11.5 0 0 1 6 0C17.3 4.7 18.3 5 18.3 5c.7 1.6.2 2.9.1 3.2.8.8 1.3 1.9 1.3 3.2 0 4.6-2.9 5.6-5.5 5.9.4.4.8 1.1.8 2.2v3.3c0 .3.2.7.8.6A12 12 0 0 0 12 0z"/></svg>


</body>
<!----------------------JavaScript------------------------>
<script>
  InitWebSocket()
  function InitWebSocket()
  {
    websock = new WebSocket('ws://'+window.location.hostname+':81/');
    websock.onmessage=function(evt)
    {
       JSONobj = JSON.parse(evt.data);

       document.getElementById('loading_animation').innerHTML ="";
       document.getElementById('switch_text').innerHTML ="Use This Switch To Turn The Motor ON or OFF ";
       var P=JSONobj.percentage;
       if (P > 100 ||  P< 0) {
            document.getElementById('percentage').style.color = "red";
            document.getElementById('capacity').style.color = "red";
       
            document.getElementById('capacity').innerHTML = "WARNING !";
            document.getElementById('percentage').innerHTML = "Water > 100%";

            var height = parseInt(JSONobj.percentage);
            document.getElementById("water").style.height = "100%";
            document.getElementById("water").style.border = "5px solid red";
                             }
       else {
            document.getElementById('percentage').style.color = "#0C5BF3";
            document.getElementById('capacity').style.color = "#0C5BF3";
            document.getElementById("water").style.border = "0px solid red";         
            document.getElementById('capacity').innerHTML = JSONobj.capacity +" Liters";
       
       document.getElementById('percentage').innerHTML = JSONobj.percentage +" %";
       var height = parseInt(JSONobj.percentage);
       document.getElementById("water").style.height = height+"%";

            }
        document.getElementById('FANbtn').checked = (JSONobj.LEDonoff == 'OFF');
    }
  }
  //----------------------------------------------------
        function fanONOFF() {
    let FANbtn = 'LEDonoff=ON';
    if (document.getElementById('FANbtn').checked) {
      FANbtn = 'LEDonoff=OFF';
    }
    websock.send(FANbtn);
  }
</script>
</html>
)=====";