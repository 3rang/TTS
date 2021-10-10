# NAME

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

# High Level Arquitecture

## More coming soon..
