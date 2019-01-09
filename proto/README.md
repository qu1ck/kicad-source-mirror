# Experimental
## Protobuf definitions for KiCad

Sample output of proto_test executable:

```
parts {
  name: "ANTIMATTER CONDENSER"
  power: true
  properties {
    name: "OUTPUT"
    value: "121GW"
    visible: true
  }
}
shapes {
  line_type: DOTTED
  line {
    points {
      x: 2
      y: 3
    }
  }
}
shapes {
  circle {
    center {
      y: 100
    }
    radius: 42
  }
}
pins {
  type: BIDIRECTIONAL
  at {
    x: 100
    y: 100
  }
  angle: 100
  name {
    text: "1"
  }
}
pins {
  type: PASSIVE
  number {
    text: "2"
  }
}
```
