# Deep Learning Based TTS (Text-to-Speech) Application for Embedded Device (x86 and ARM )

## Project Structure
This is the current structure of the project
```shell
mainApp
├── CMakeLists.txt		
├── Dockerfile			# Docker 
├── docs			# docs and images
│   └── images
│       └── url.png
├── explore			# Experimental juypter notebook for tts 
│   └── notebooks
│       └── tts_tflite.ipynb
├── LICENSE
├── model			# tflite models
├── README.md
├── scripts 			# Helper Scripts
└── src				# Source Code
    ├── audioplayer 		# Pulse Audio based Audio player (W.I.P)
    ├── main			# Actual Start of Application 
    └── tts			# Text-to-Speech Application based on tflite

```

# Setup Docker 

```shell

# Create a workspace for your work
mkdir workspace-name
cd workspace-name

# clone the repo.
git clone git@github.com:3rang/TTS.git
cd TTS/

# Build the docker container to setup development environment 
docker build -f Dockerfile -t tts .
 
# run docker 
docker run -v $PWD:/home/TTS/ --network host -it tts:latest

```

# Build the Application 
```shell
cd TTS
mkdir build
cmake ..
make -j$(nproc)
```
# Run Application 
```shell
./mainApp $json_file_path$ $text$ $tflitemodel$ $vocodermodel$

```
# Tensorflow-lite Model
```shell
$json_file_path$ = model/ljspeech_mapper.json 
$tflitemodel$ = model/fastspeech2_quan.tflite
$vocodermodel$ = model/mb_melgan.tflite


Note
develop an own tensorflow-lite model and replace model 

``` 

## More coming soon..
