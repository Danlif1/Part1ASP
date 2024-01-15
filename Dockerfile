# Use an official Ubuntu runtime as a parent image
FROM ubuntu:latest

# Set the working directory inside the container
WORKDIR /

# Copy the entire project to the working directory
COPY . .

# Install necessary dependencies
RUN apt-get update && \
    apt-get install -y g++ && \
    apt-get install -y libgtest-dev cmake

# Build the C++ code
RUN cmake -B build -S . && \
    cmake --build build

RUN ls -l

# Command to run when the container starts
CMD ["ctest --test-dir build --output-on-failure"]
#CMD ["pwd && ls -l"]
