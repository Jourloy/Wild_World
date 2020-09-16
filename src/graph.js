const log = {
    bright(text) { return `\x1b[1m${text}\x1b[0m` },
    dim(text) { return `\x1b[2m${text}\x1b[0m` },
    underscore(text) { return `\x1b[4m${text}\x1b[0m` },
    blink(text) { return `\x1b[5m${text}\x1b[0m` },
    reverse(text) { return `\x1b[7m${text}\x1b[0m` },
    hidden(text) { return `\x1b[8m${text}\x1b[0m` },

    fgBlack(text) { return `\x1b[30m${text}\x1b[0m` },
    fgRed(text) { return `\x1b[31m${text}\x1b[0m` },
    fgGreen(text) { return `\x1b[32m${text}\x1b[0m` },
    fgYellow(text) { return `\x1b[33m${text}\x1b[0m` },
    fgBlue(text) { return `\x1b[34m${text}\x1b[0m` },
    fgMagenta(text) { return `\x1b[35m${text}\x1b[0m` },
    fgCyan(text) { return `\x1b[36m${text}\x1b[0m` },
    fgWhite(text) { return `\x1b[37m${text}\x1b[0m` },

    bgBlack(text) { return `\x1b[40m${text}\x1b[0m` },
    bgRed(text) { return `\x1b[41m${text}\x1b[0m` },
    bgGreen(text) { return `\x1b[42m${text}\x1b[0m` },
    bgYellow(text) { return `\x1b[43m${text}\x1b[0m` },
    bgBlue(text) { return `\x1b[44m${text}\x1b[0m` },
    bgMagenta(text) { return `\x1b[45m${text}\x1b[0m` },
    bgCyan(text) { return `\x1b[46m${text}\x1b[0m` },
    bgWhite(text) { return `\x1b[47m${text}\x1b[0m` },
}

const water = log.bgCyan(' ');
const grass = log.bgGreen(' ');
const player = log.bgGreen(log.blink(log.fgRed('Θ')))

exports.TestGenerateWorld = function() {
    console.log(`
${grass}${grass}${water}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}
${grass}${grass}${water}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}
${grass}${grass}${grass}${water}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}
${grass}${grass}${grass}${water}${grass}${grass}${grass}${grass}${grass}${player}${grass}${grass}${grass}${grass}${grass}
${grass}${grass}${grass}${grass}${water}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}
${grass}${grass}${grass}${grass}${water}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}
${grass}${grass}${grass}${grass}${grass}${water}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}${grass}
    `)
}