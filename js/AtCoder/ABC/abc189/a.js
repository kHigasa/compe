function main(s) {
    if (s[0]==s[1] && s[0]==s[2]) {
        console.log('Won');
    } else {
        console.log('Lost');
    }
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));