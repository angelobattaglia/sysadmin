# Docker

Docker is a popular open-source platform used for developing, shipping, and running applications. At its core, Docker is about containers. A container is a lightweight, standalone, executable package that includes everything needed to run a piece of software, including the code, runtime, libraries, and system tools. Containers are isolated from each other and the host system, ensuring consistent operation regardless of where the container is deployed.
Now, let's see some terminology and concepts that revolve around this "container" thing:

2. **Images**: Containers are created from Docker images. An image is a lightweight, standalone, and executable software package that includes everything needed to run a container: code, runtime, system tools, libraries, and settings. Docker images are built from a Dockerfile, which is a script composed of various commands and arguments that define the image.

3. **Dockerfile**: A Dockerfile is a text document that contains all the commands a user could call on the command line to assemble an image. Using `docker build` users can create an image from a Dockerfile.

4. **Docker Hub and Registries**: Docker Hub is a service provided by Docker for finding and sharing container images with your team. Private and public repositories can be used to host container images. Other registries include AWS Elastic Container Registry, Google Container Registry, etc.

5. **Portability and Consistency**: Docker ensures that an application works seamlessly in any environment. A Docker container runs identically whether on a developer’s laptop, a test server, or in production, which eliminates the “it works on my machine” problem.

6. **Microservices Architecture**: Docker is conducive to microservices architecture – a design approach to build a single application as a suite of small services, each running in its own container.

7. **Docker Compose**: For defining and running multi-container Docker applications. With Compose, you use a YAML file to configure your application’s services, networks, and volumes, and then create and start all the services from your configuration with a single command.

8. **Docker Swarm**: Docker’s orchestration and cluster management tool. Swarm lets you manage a cluster of Docker hosts and deploy application services to them in a scalable, reliable way.

Docker simplifies the deployment of applications, as it allows them to be bundled with all of their dependencies into a single container. This can greatly reduce conflicts between teams running different software on the same infrastructure.

## Minimal docker example: an hello world app in python

### Create the Python Application
First, we'll create a simple Python script. Let's name it `app.py`.

```python
# app.py
print("Hello, World!")
```

### Create a Dockerfile
Next, we'll create a Dockerfile to specify how our Docker image should be built.

```Dockerfile
# Dockerfile
FROM python:3.8-slim

# Copy the Python script into the container at /app
WORKDIR /app
COPY app.py /app

# Run the Python script when the container launches
CMD ["python", "./app.py"]
```

This Dockerfile performs the following steps:
1. Start from a base image containing Python 3.8 (`python:3.8-slim`).
2. Set the working directory inside the container to `/app`.
3. Copy the `app.py` file from your local directory into `/app` in the container.
4. Set the command to run the Python script when the container starts.

### Build the Docker Image
Now, build the Docker image from the Dockerfile. Run this command in the directory containing the Dockerfile and `app.py`.

```bash
docker build -t hello-world .
```

This command builds the Docker image and tags it (`-t`) with the name `hello-world`.

### Run the Docker Container
Finally, run a container based on the image you just built:

```bash
docker run hello-world
```

This command creates and starts a container from the `hello-world` image. You should see the output `Hello, World!` in your terminal, which demonstrates that the Python script is executed inside the container.

That's it! This is a minimal example to demonstrate the basic workflow of Docker: writing a simple application, creating a Dockerfile, building an image, and running a container from that image.


## Using docker with something like "numpy"

### Create the Python Application
First, let's modify our `app.py` to use `numpy`.

```python
# app.py
import numpy as np

print("Hello, World! Here's a random number from NumPy:", np.random.rand())
```

### Create a Dockerfile
Now, we'll update our Dockerfile to set up a virtual environment and install `numpy`.

```Dockerfile
# Dockerfile
FROM python:3.8-slim

# Set the working directory in the container
WORKDIR /app

# Copy the Python script and requirements file into the container
COPY app.py /app
COPY requirements.txt /app

# Set up a virtual environment
RUN python -m venv venv
ENV PATH="/app/venv/bin:$PATH"

# Install numpy
RUN pip install numpy

# Run the Python script when the container launches
CMD ["python", "./app.py"]
```

In this Dockerfile:
1. We set the working directory to `/app`.
2. We copy `app.py` and a `requirements.txt` file into `/app` in the container.
3. We create a Python virtual environment inside the container.
4. We activate the virtual environment and install `numpy`.

### Create a Requirements File
Create a `requirements.txt` file specifying `numpy` and its version.

```
numpy==1.21.0
```

### Build the Docker Image
Build the Docker image using the updated Dockerfile.

```bash
docker build -t hello-world-numpy .
```

### Run the Docker Container
Finally, run the container based on the new image.

```bash
docker run hello-world-numpy
```

This command will output a greeting message along with a random number generated by NumPy, demonstrating that NumPy is installed and working inside the container's virtual environment.

This example shows how to include a Python virtual environment and specific dependencies (like `numpy`) in a Docker container, which is a common practice for Python development to ensure consistent and isolated environments.


## Uploading a Docker Image to Docker Hub

### Create a Docker Hub Account
If you don't already have a Docker Hub account, you'll need to create one. Go to [Docker Hub](https://hub.docker.com/) and sign up for a free account.

### Log in to Docker Hub from the Command Line
Once you have your Docker Hub account, you need to log in from your command line. Open your terminal and use the following command:

```bash
docker login
```

You'll be prompted to enter your Docker Hub username and password. Once logged in, you can start pushing images to your Docker Hub repository.

### Tag Your Docker Image
Before you can upload your image to Docker Hub, you need to tag it with your Docker Hub username and the repository name you want to use. The general format for the tag is:

```bash
docker tag local-image:tag username/repository:tag
```

For example, if your Docker Hub username is `username` and you want to name your repository `hello-world-numpy`, and you're using the `latest` tag, the command would be:

```bash
docker tag hello-world-numpy:latest username/hello-world-numpy:latest
```

This command tags the `hello-world-numpy` image from our previous example.

### Push the Image to Docker Hub
Now, push the tagged image to Docker Hub using the following command:

```bash
docker push username/repository:tag
```

Continuing our example, you would run:

```bash
docker push username/hello-world-numpy:latest
```

This command uploads the `hello-world-numpy` image to your Docker Hub repository.

### Verify the Upload
After the push operation completes, go to your Docker Hub account and check your repositories. You should see the `hello-world-numpy` repository listed with the `latest` tag.

### Note:
- Ensure that your local image name and tag match exactly with the ones you're trying to push to Docker Hub.
- Remember to replace `username`, `repository`, and `tag` with your actual Docker Hub username, desired repository name, and tag.
- If you want your repository to be private, you need to set it as private on Docker Hub. By default, repositories are public.

