import os from "os"

if (typeof Bun == "undefined") {
  throw new Error("use Bun bozo")
}

const network = Object.values(os.networkInterfaces())
  .filter(Boolean)
  .flatMap(entry => entry)
  .find(entry => !entry.internal)

if (!network) {
  throw new Error("public ip addr not available")
}

const decoder = new TextDecoder()

Bun.listen({
  hostname: network.address,
  port: 3000,
  socket: {
    data(socket, data) {
      console.log("From Client:",decoder.decode(data));
    },
    open(socket) {
      console.log("Client connected");
      console.log(socket)
    },
  },
});

console.log(`listening in ${network.address}`)

