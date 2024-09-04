function extendedGCD(a, b) {
  if (b === 0) {
    return [a, 1, 0];
    }
    
    let [g, x1, y1] = extendedGCD(b, a % b);
     let x = y1;
     let y = x1 - Math.floor(a / b) * y1;
    
      return [g, x, y];
}

function findSolution(a, b) {
 let [g, x, y] = extendedGCD(a, b);

    if (g !== 1) {
      return "No Solution";
    }

    if (x < 0) {
      let k = Math.ceil(-x / b);
       x += k * b;
       y -= k * a;
      } else {
      let k = Math.floor(x / b);
       x -= k * b;
       y += k * a;
    }

        return `${x} ${y}`;
}

function main(input) {
  let lines = input.trim().split("\n");
  let t = parseInt(lines[0]);
   let results = [];

for (let i = 1; i <= t; i++) {
  let [a, b] = lines[i].split(" ").map(Number);
   results.push(findSolution(a, b));
    }

    console.log(results.join("\n"));
}
