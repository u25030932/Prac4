FROM ubuntu

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y make g++ valgrind gdb
RUN make

CMD ["./main"]
