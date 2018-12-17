# dust_collector
This is a machine that helps collect wet/dry dust. 
As defult the dust cover is on the wet bin leaving the dry bin open to collect suspended dust that will then be anlysed for chemical composition. When it starts raining the cover moves from the wet bin to the dry bin. During the storm rain is collected giving total rainfall and allowing for rain (and rain borne dust) chemical analysis.

- Rain sensor gives a 1/0 for rain and an analog signal, we will use the digital signal for v0.1
- Engine test was successful
- wet/dry switches give a low signal, we need a higher output to sensor or input to arduino (or a new switch...)
- Timer needs to be calibrated and then each storm event will have a start timestamp.
