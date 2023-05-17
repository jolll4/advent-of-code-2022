import * as fs from "fs";

const Transpose = (pilesList: string[][]): string[][] => {
  const transposePiles: string[][] = [];
  pilesList.reverse().forEach((row) => {
    for (let i = 0; i < row.length; i++) {
      if (row[i] != "x") {
        if (transposePiles[i]) {
          transposePiles[i].push(row[i]);
        } else {
          transposePiles[i] = [row[i]];
        }
      }
    }
  });
  return transposePiles;
};

const PilesListMaker = (): string[][] => {
  const pilesImport = fs
    .readFileSync("input_files/day5-input-piles.txt", "utf8")
    .split("\n");

  const pilesList = pilesImport.map((x) =>
    x
      .replaceAll("        ", " x x")
      .replaceAll("    ", " x")
      .replaceAll("[", "")
      .replaceAll("]", "")
      .split(" ")
  );

  pilesList.pop();
  return pilesList;
};

const pilesList: string[][] = PilesListMaker();
const pilesList2: string[][] = PilesListMaker();

const piles1: string[][] = Transpose(pilesList);
const piles2: string[][] = Transpose(pilesList2);

const movesImport = fs
  .readFileSync("input_files/day5-input-moves.txt", "utf8")
  .split("\n");

movesImport.forEach((command) => {
  const commands: string[] = command.split(" ");
  const start: number = parseInt(commands[3]) - 1;
  const end: number = parseInt(commands[5]) - 1;
  const amount: number = parseInt(commands[1]);
  const movePile: string[] = [];

  for (let i = 0; i < amount; i++) {
    const moving1 = piles1[start].pop();
    if (moving1) piles1[end].push(moving1);

    const moving2 = piles2[start].pop();
    if (moving2) movePile.push(moving2);
  }
  piles2[end] = piles2[end].concat(movePile.reverse());
});

let answer1: String = "";
piles1.forEach((x) => {
  answer1 = answer1.concat(String(x.slice(-1)[0]));
});

let answer2: String = "";
piles2.forEach((x) => {
  answer2 = answer2.concat(String(x.slice(-1)[0]));
});

console.log(answer1);
console.log(answer2);
