//
//See post: https://asmaloney.com/2014/01/code/creating-an-interactive-map-with-leaflet-and-openstreetmap/
var markers = [
  {
    name: 'Argentina',
    url: 'https://en.wikipedia.org/wiki/Argentina',
    lat: -38.416096,
    lng: -63.616673,
  },
]

var myURL = jQuery('script[src$="static_markers.js"]')
    .attr('src')
    .replace('static_markers.js', '')

var myIcon = L.icon({
    iconUrl: myURL + 'images/pin24.png',
    iconRetinaUrl: myURL + 'images/pin48.png',
    iconSize: [29, 24],
    iconAnchor: [9, 21],
    popupAnchor: [0, -14],
})

for (var i = 0; i < markers.length; ++i) {
    L.marker([markers[i].lat, markers[i].lng], { icon: myIcon })
	.bindPopup(
	    '<a href="' +
		markers[i].url +
		'" target="_blank">' +
		markers[i].name +
		'</a>'
	)
	.addTo(map)
}
