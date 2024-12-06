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

Bun.serve({
  hostname: network.address,
  port: 3000,
  fetch(req, server) {
    if (server.upgrade(req)) {
      return;
    }
    return new Response("Upgrade failed", { status: 500 });
  },
  websocket: {
    message(ws, message) {
      console.log("Client Message", message)
    },
    open(ws) {
      console.log("Client Connect:", ws.remoteAddress)
    },
    close(ws, code, message) {
      console.log("Client Close:", code, message)
    },
    error(ws, error) {
      console.log("Client Error:", error.message, error)
    },
  },
});

console.log(`listening in ${network.address}`)

