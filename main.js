class Node {
    /**
     * 
     * @param {any} data - Data of any type.
     * @param {number} id - The id of this node.
     */
    constructor(data, id) {
        this.data = data;
        this.id = id;
    }
}

class Layer {
    /**
     * 
     * @param {Array<Node>} nodes - All of the nodes in the layer.
     * @param {Array<Array<number>>} [inputs=[]] - The inputs of this node.
     * @param {Array<number>} [outputs=[]] - The outputs of this node.
     */
    constructor(nodes, inputs = [], outputs = []) {
        this.nodes = nodes;
        this.inputs = inputs;
        this.outputs = outputs;
    }
}

class NeuralNetwork {
    /**
     * 
     * @param {Layer} inputLayer - The input layer of this neural network.
     * @param {Array<Layer>} hiddenLayers - The hidden layers of this network.
     * @param {Layer} outputLayer - The output layers of the network.
     */
    constructor(inputLayer, hiddenLayers, outputLayer) {
        this.inputLayer = inputLayer;
        this.hiddenLayers = hiddenLayers;
        this.outputLayer = outputLayer;
    }
}

/**
 * 
 * @param {NeuralNetwork} network - The network to be calculated.
 * 
 * @returns {Layer} - The output layer that it returns.
 */
function calculateNetwork(network) {
    const currNet = network;
    for (let hiddenLayer in currNet.hiddenLayers) {
        const currLayer = currNet.hiddenLayers[hiddenLayer];
        console.log(currLayer);
        for (let node in currLayer.nodes) {
            console.log(currLayer.nodes[node]);
            currNet.hiddenLayers[hiddenLayer].nodes[node].data = currNet.hiddenLayers[hiddenLayer].inputs;
        }
    }
}

//Create a test network
let net = new NeuralNetwork(new Layer([new Node(3, 0), new Node(1, 1)], [], [2,3,4]), 
        [new Layer([new Node(null, 2), new Node(null, 3), new Node(null, 4)], [[0,1], [0]], [[5,6], [-1]])], new Layer([new Node(null, 5), new Node(null, 6)], [1], []));

calculateNetwork(net);