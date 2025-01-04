const STATE_TOPIC = "topic:state";
const PICT_DIR = "node_modules/.picture"

const state = {
  count: 0
}

const server = Bun.serve({
  async fetch(request, server) {
    const url = new URL(request.url);
    console.log(url.pathname)

    if (url.pathname == "/ws" && server.upgrade(request)) {
      return;
    }

    if (request.method == "GET" && url.pathname == "/state") {
      return Response.json(state);
    }

    if (request.method == "POST" && url.pathname == "/add") {
      add_publish();
      return new Response();
    }

    if (request.method == "GET" && url.pathname == "/picture") {
      return new Response(Bun.file(PICT_DIR));
    }

    if (request.method == "POST" && url.pathname == "/picture") {
      await Bun.write(PICT_DIR, request).catch(err => console.error("cannot write picture:",err));
      return new Response();
    }

    return new Response(void 0, { status: 404 })
  },

  error(error) {
    console.error("[ERROR]",error)
    return new Response(void 0, { status: 500 })
  },

  websocket: {
    open(ws) {
      ws.subscribe(STATE_TOPIC);
    },
    message(_, message) {
      try {
        const data = JSON.parse(message);

        if (data["kind"] == "add") {
          add_publish();
        }

      } catch (err) {
        console.error(err)
      }
    },
    close(ws, _, __) {
      ws.unsubscribe(STATE_TOPIC);
    },
  }
})

console.log("listening", server.url.toJSON())

function add_publish() {
  state.count += 1;
  server.publish(STATE_TOPIC, JSON.stringify({
    kind: "state",
    value: state,
  }))
}
