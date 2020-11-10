import React from "react";
import { Map, TileLayer, Marker, Popup, Circle } from "react-leaflet";
import 'leaflet/dist/leaflet.css';
import L from 'leaflet';


export default function MyMap(props) {
	delete L.Icon.Default.prototype._getIconUrl;
	L.Icon.Default.mergeOptions({
		iconRetinaUrl: require('leaflet/dist/images/marker-icon-2x.png'),
		iconUrl: require('leaflet/dist/images/marker-icon.png'),
		shadowUrl: require('leaflet/dist/images/marker-shadow.png')
	});

	let i = props.index;

	return (
		<Map center={props.coord[0] !== "" && props.coord[0] !== 0 ? props.coord : [48.8534, 2.3488]} zoom={12} minZoom={2} maxZoom={18} style={{height: 350, zIndex:0}}>
			<TileLayer
				attribution="&amp;copy <a href=&quot;http://osm.org/copyright&quot;>OpenStreetMap</a> contributors"
					url="https://cartodb-basemaps-{s}.global.ssl.fastly.net/light_all/{z}/{x}/{y}.png"
				/>
						{(props.coord[0] !== "" && props.coord[0] !== 0) && (<Marker position={props.coord}>
						<Popup>Moi</Popup>
					</Marker>)}
						{(typeof(i) !== 'number' && props.others.length > 0) && props.others.map((e, index) => (<Circle key={`circle-${index}`} center={[e.latitude, e.longitude]} radius={350}><Popup>{e.username}</Popup></Circle>))}
							{(typeof(i) === 'number' && props.others.length > 0 && props.others[i]) && <Circle center={[props.others[i].latitude, props.others[i].longitude]} radius={350}><Popup>{props.others[i].username}</Popup></Circle>}
					</Map>
	)
}
