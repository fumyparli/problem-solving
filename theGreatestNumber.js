const solution = (numbers) =>
    numbers.sort((a, b) => (b + "" + a) * 1 - (a + "" + b) * 1).join("")[0] ===
    "0"
        ? "0"
        : numbers.join("");
