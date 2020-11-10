const faker = require('faker');
const axios = require('axios');
const uuidv1 = require('uuid/v1');
const bcrypt = require('bcrypt');
const db = require('../models/seed.js');
const dbInt = require('../models/interest.js');
//119
let man = ["https://s3.amazonaws.com/uifaces/faces/twitter/isnifer/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/trubeatto/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/sawalazar/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/Chakintosh/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/el_fuertisimo/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/dvdwinden/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/danro/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/rtgibbons/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/bungiwan/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/eduardostuart/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/danvierich/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/smalonso/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/jpscribbles/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/geobikas/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/supervova/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/mizko/128.jpg","https://s3.amazonaws.com/uifaces/faces/twitter/hellofeverrrr/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/Shriiiiimp/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/patrickcoombe/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/yalozhkin/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/adamnac/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/jarjan/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/luxe/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/uxalex/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/manekenthe/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/sokaniwaal/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/elliotlewis/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/roybarberuk/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/borantula/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/xripunov/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/enda/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/aaroni/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/xadhix/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/cicerobr/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/dudestein/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/peejfancher/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/nfedoroff/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/gu5taf/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/samuelkraft/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/jmillspaysbills/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/lmjabreu/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/bartjo/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/shalt0ni/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/estebanuribe/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/markretzloff/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/designervzm/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/dallasbpeters/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/r_oy/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/johannesneu/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/Elt_n/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/herbigt/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/dpmachado/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/teylorfeliz/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/mizko/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/garand/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/lewisainslie/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/adammarsbar/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/thedamianhdez/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/themikenagle/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/kohette/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/raphaelnikson/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/puzik/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/keryilmaz/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/mugukamil/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/jjshaw14/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/jm_denis/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/coderdiaz/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/imammuht/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/juangomezw/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/normanbox/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/BroumiYoussef/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/magoo04/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/yayteejay/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/maz/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/miguelkooreman/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/kinday/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/davidcazalis/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/guillemboti/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/davecraige/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/karsh/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/opnsrce/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/_williamguerra/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/kolmarlopez/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/abdulhyeuk/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/gregsqueeb/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/angelcreative/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/salimianoff/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/sgaurav_baghel/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/instalox/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/shanehudson/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/ashocka18/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/spedwig/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/eduardostuart/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/muridrahhal/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/kostaspt/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/BrianPurkiss/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/kosmar/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/cdharrison/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/dactrtr/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/yecidsm/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/ehsandiary/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/jlsolerdeltoro/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/mahdif/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/ManikRathee/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/sawrb/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/themrdave/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/txcx/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/canapud/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/yalozhkin/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/krasnoukhov/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/olaolusoga/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/teddyzetterlund/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/hai_ninh_nguyen/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/xilantra/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/mutlu82/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/gabrielrosser/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/chandlervdw/128.jpg",
"https://s3.amazonaws.com/uifaces/faces/twitter/okandungel/128.jpg", 'https://randomuser.me/api/portraits/men/93.jpg',
  'https://randomuser.me/api/portraits/men/36.jpg',
  'https://randomuser.me/api/portraits/men/72.jpg',
  'https://randomuser.me/api/portraits/men/96.jpg',
  'https://randomuser.me/api/portraits/men/1.jpg',
  'https://randomuser.me/api/portraits/men/22.jpg',
  'https://randomuser.me/api/portraits/men/55.jpg',
  'https://randomuser.me/api/portraits/men/4.jpg',
  'https://randomuser.me/api/portraits/men/62.jpg',
  'https://randomuser.me/api/portraits/men/51.jpg',
  'https://randomuser.me/api/portraits/men/24.jpg',
  'https://randomuser.me/api/portraits/men/9.jpg',
  'https://randomuser.me/api/portraits/men/45.jpg',
  'https://randomuser.me/api/portraits/men/87.jpg',
  'https://randomuser.me/api/portraits/men/58.jpg',
  'https://randomuser.me/api/portraits/men/90.jpg',
  'https://randomuser.me/api/portraits/men/70.jpg',
  'https://randomuser.me/api/portraits/men/69.jpg',
  'https://randomuser.me/api/portraits/men/43.jpg',
  'https://randomuser.me/api/portraits/men/44.jpg',
  'https://randomuser.me/api/portraits/men/56.jpg',
  'https://randomuser.me/api/portraits/men/74.jpg',
  'https://randomuser.me/api/portraits/men/70.jpg',
  'https://randomuser.me/api/portraits/men/24.jpg',
  'https://randomuser.me/api/portraits/men/66.jpg',
  'https://randomuser.me/api/portraits/men/93.jpg',
  'https://randomuser.me/api/portraits/men/49.jpg',
  'https://randomuser.me/api/portraits/men/85.jpg',
  'https://randomuser.me/api/portraits/men/11.jpg',
  'https://randomuser.me/api/portraits/men/5.jpg',
  'https://randomuser.me/api/portraits/men/37.jpg',
  'https://randomuser.me/api/portraits/men/67.jpg',
  'https://randomuser.me/api/portraits/men/6.jpg',
  'https://randomuser.me/api/portraits/men/38.jpg',
  'https://randomuser.me/api/portraits/men/8.jpg',
  'https://randomuser.me/api/portraits/men/65.jpg',
  'https://randomuser.me/api/portraits/men/63.jpg',
  'https://randomuser.me/api/portraits/men/94.jpg',
  'https://randomuser.me/api/portraits/men/68.jpg',
  'https://randomuser.me/api/portraits/men/52.jpg',
  'https://randomuser.me/api/portraits/men/20.jpg',
  'https://randomuser.me/api/portraits/men/29.jpg',
  'https://randomuser.me/api/portraits/men/72.jpg',
  'https://randomuser.me/api/portraits/men/42.jpg',
  'https://randomuser.me/api/portraits/men/23.jpg',
  'https://randomuser.me/api/portraits/men/24.jpg',
  'https://randomuser.me/api/portraits/men/61.jpg',
  'https://randomuser.me/api/portraits/men/77.jpg',
  'https://randomuser.me/api/portraits/men/65.jpg',
  'https://randomuser.me/api/portraits/men/1.jpg',
  'https://randomuser.me/api/portraits/men/98.jpg',
  'https://randomuser.me/api/portraits/men/53.jpg',
  'https://randomuser.me/api/portraits/men/48.jpg',
  'https://randomuser.me/api/portraits/men/89.jpg',
  'https://randomuser.me/api/portraits/men/29.jpg',
  'https://randomuser.me/api/portraits/men/72.jpg',
  'https://randomuser.me/api/portraits/men/82.jpg',
  'https://randomuser.me/api/portraits/men/1.jpg',
  'https://randomuser.me/api/portraits/men/31.jpg',
  'https://randomuser.me/api/portraits/men/65.jpg',
  'https://randomuser.me/api/portraits/men/80.jpg',
  'https://randomuser.me/api/portraits/men/96.jpg',
  'https://randomuser.me/api/portraits/men/86.jpg',
  'https://randomuser.me/api/portraits/men/33.jpg',
  'https://randomuser.me/api/portraits/men/88.jpg',
  'https://randomuser.me/api/portraits/men/83.jpg',
  'https://randomuser.me/api/portraits/men/19.jpg',
  'https://randomuser.me/api/portraits/men/98.jpg',
  'https://randomuser.me/api/portraits/men/57.jpg',
  'https://randomuser.me/api/portraits/men/19.jpg',
  'https://randomuser.me/api/portraits/men/89.jpg',
  'https://randomuser.me/api/portraits/men/70.jpg',
  'https://randomuser.me/api/portraits/men/71.jpg',
  'https://randomuser.me/api/portraits/men/45.jpg',
  'https://randomuser.me/api/portraits/men/25.jpg',
  'https://randomuser.me/api/portraits/men/96.jpg',
  'https://randomuser.me/api/portraits/men/17.jpg',
  'https://randomuser.me/api/portraits/men/48.jpg',
  'https://randomuser.me/api/portraits/men/62.jpg',
  'https://randomuser.me/api/portraits/men/89.jpg'
];
// 161
let woman = ["https://s3.amazonaws.com/uifaces/faces/twitter/fotomagin/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/joannefournier/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/maiklam/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/superoutman/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/overcloacked/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/m_kalibry/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/omnizya/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/jennyshen/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/jqiuss/128.jpg", "https://s3.amazonaws.com/uifaces/faces/twitter/millinet/128.jpg", "https://randomuser.me/api/portraits/women/10.jpg",
"https://randomuser.me/api/portraits/women/10.jpg",
"https://randomuser.me/api/portraits/women/9.jpg",
"https://randomuser.me/api/portraits/women/23.jpg",
"https://randomuser.me/api/portraits/women/4.jpg",
"https://randomuser.me/api/portraits/women/76.jpg",
"https://randomuser.me/api/portraits/women/9.jpg",
"https://randomuser.me/api/portraits/women/72.jpg",
"https://randomuser.me/api/portraits/women/23.jpg",
"https://randomuser.me/api/portraits/women/56.jpg",
"https://randomuser.me/api/portraits/women/66.jpg",
"https://randomuser.me/api/portraits/women/11.jpg",
"https://randomuser.me/api/portraits/women/93.jpg",
"https://randomuser.me/api/portraits/women/30.jpg",
"https://randomuser.me/api/portraits/women/86.jpg",
"https://randomuser.me/api/portraits/women/38.jpg",
"https://randomuser.me/api/portraits/women/96.jpg",
"https://randomuser.me/api/portraits/women/34.jpg",
"https://randomuser.me/api/portraits/women/79.jpg",
"https://randomuser.me/api/portraits/women/32.jpg",
"https://randomuser.me/api/portraits/women/24.jpg",
"https://randomuser.me/api/portraits/women/64.jpg",
"https://randomuser.me/api/portraits/women/26.jpg",
"https://randomuser.me/api/portraits/women/90.jpg",
"https://randomuser.me/api/portraits/women/2.jpg",
"https://randomuser.me/api/portraits/women/0.jpg",
"https://randomuser.me/api/portraits/women/16.jpg",
"https://randomuser.me/api/portraits/women/55.jpg",
"https://randomuser.me/api/portraits/women/26.jpg",
"https://randomuser.me/api/portraits/women/20.jpg",
"https://randomuser.me/api/portraits/women/50.jpg",
"https://randomuser.me/api/portraits/women/70.jpg",
"https://randomuser.me/api/portraits/women/54.jpg",
"https://randomuser.me/api/portraits/women/75.jpg",
"https://randomuser.me/api/portraits/women/78.jpg",
"https://randomuser.me/api/portraits/women/33.jpg",
"https://randomuser.me/api/portraits/women/71.jpg",
"https://randomuser.me/api/portraits/women/17.jpg",
"https://randomuser.me/api/portraits/women/34.jpg",
"https://randomuser.me/api/portraits/women/32.jpg",
"https://randomuser.me/api/portraits/women/20.jpg",
"https://randomuser.me/api/portraits/women/35.jpg",
"https://randomuser.me/api/portraits/women/46.jpg",
"https://randomuser.me/api/portraits/women/70.jpg",
"https://randomuser.me/api/portraits/women/61.jpg",
"https://randomuser.me/api/portraits/women/4.jpg",
"https://randomuser.me/api/portraits/women/38.jpg",
"https://randomuser.me/api/portraits/women/77.jpg",
"https://randomuser.me/api/portraits/women/66.jpg",
"https://randomuser.me/api/portraits/women/36.jpg",
"https://randomuser.me/api/portraits/women/11.jpg",
"https://randomuser.me/api/portraits/women/70.jpg",
"https://randomuser.me/api/portraits/women/38.jpg",
"https://randomuser.me/api/portraits/women/58.jpg",
"https://randomuser.me/api/portraits/women/93.jpg",
"https://randomuser.me/api/portraits/women/96.jpg",
"https://randomuser.me/api/portraits/women/25.jpg",
"https://randomuser.me/api/portraits/women/50.jpg",
"https://randomuser.me/api/portraits/women/65.jpg",
"https://randomuser.me/api/portraits/women/84.jpg",
"https://randomuser.me/api/portraits/women/26.jpg",
"https://randomuser.me/api/portraits/women/42.jpg",
"https://randomuser.me/api/portraits/women/12.jpg",
"https://randomuser.me/api/portraits/women/9.jpg",
"https://randomuser.me/api/portraits/women/66.jpg",
"https://randomuser.me/api/portraits/women/80.jpg",
"https://randomuser.me/api/portraits/women/54.jpg",
"https://randomuser.me/api/portraits/women/45.jpg",
"https://randomuser.me/api/portraits/women/58.jpg",
"https://randomuser.me/api/portraits/women/6.jpg",
"https://randomuser.me/api/portraits/women/20.jpg",
"https://randomuser.me/api/portraits/women/9.jpg",
"https://randomuser.me/api/portraits/women/37.jpg",
"https://randomuser.me/api/portraits/women/84.jpg",
"https://randomuser.me/api/portraits/women/33.jpg",
"https://randomuser.me/api/portraits/women/4.jpg",
"https://randomuser.me/api/portraits/women/46.jpg",
"https://randomuser.me/api/portraits/women/79.jpg",
"https://randomuser.me/api/portraits/women/25.jpg",
"https://randomuser.me/api/portraits/women/76.jpg",
"https://randomuser.me/api/portraits/women/56.jpg",
"https://randomuser.me/api/portraits/women/53.jpg",
"https://randomuser.me/api/portraits/women/1.jpg",
"https://randomuser.me/api/portraits/women/54.jpg",
"https://randomuser.me/api/portraits/women/30.jpg",
"https://randomuser.me/api/portraits/women/18.jpg",
"https://randomuser.me/api/portraits/women/16.jpg",
"https://randomuser.me/api/portraits/women/6.jpg",
"https://randomuser.me/api/portraits/women/46.jpg",
"https://randomuser.me/api/portraits/women/51.jpg",
"https://randomuser.me/api/portraits/women/80.jpg",
"https://randomuser.me/api/portraits/women/31.jpg",
"https://randomuser.me/api/portraits/women/74.jpg",
"https://randomuser.me/api/portraits/women/51.jpg",
"https://randomuser.me/api/portraits/women/75.jpg",
"https://randomuser.me/api/portraits/women/77.jpg",
"https://randomuser.me/api/portraits/women/74.jpg",
"https://randomuser.me/api/portraits/women/22.jpg",
"https://randomuser.me/api/portraits/women/94.jpg",
"https://randomuser.me/api/portraits/women/95.jpg",
"https://randomuser.me/api/portraits/women/13.jpg",
"https://randomuser.me/api/portraits/women/89.jpg",
"https://randomuser.me/api/portraits/women/41.jpg",
"https://randomuser.me/api/portraits/women/78.jpg",
"https://randomuser.me/api/portraits/women/16.jpg",
"https://randomuser.me/api/portraits/women/19.jpg",
"https://randomuser.me/api/portraits/women/65.jpg",
"https://randomuser.me/api/portraits/women/79.jpg",
"https://randomuser.me/api/portraits/women/4.jpg",
"https://randomuser.me/api/portraits/women/19.jpg",
"https://randomuser.me/api/portraits/women/42.jpg",
"https://randomuser.me/api/portraits/women/85.jpg",
"https://randomuser.me/api/portraits/women/11.jpg",
"https://randomuser.me/api/portraits/women/88.jpg",
"https://randomuser.me/api/portraits/women/34.jpg",
"https://randomuser.me/api/portraits/women/30.jpg",
"https://randomuser.me/api/portraits/women/19.jpg",
"https://randomuser.me/api/portraits/women/19.jpg",
"https://randomuser.me/api/portraits/women/26.jpg",
"https://randomuser.me/api/portraits/women/45.jpg",
"https://randomuser.me/api/portraits/women/63.jpg",
"https://randomuser.me/api/portraits/women/9.jpg",
"https://randomuser.me/api/portraits/women/92.jpg",
"https://randomuser.me/api/portraits/women/71.jpg",
"https://randomuser.me/api/portraits/women/15.jpg",
"https://randomuser.me/api/portraits/women/68.jpg",
"https://randomuser.me/api/portraits/women/5.jpg",
"https://randomuser.me/api/portraits/women/19.jpg",
"https://randomuser.me/api/portraits/women/57.jpg",
"https://randomuser.me/api/portraits/women/44.jpg",
"https://randomuser.me/api/portraits/women/32.jpg",
"https://randomuser.me/api/portraits/women/35.jpg",
"https://randomuser.me/api/portraits/women/15.jpg",
"https://randomuser.me/api/portraits/women/16.jpg",
"https://randomuser.me/api/portraits/women/76.jpg",
"https://randomuser.me/api/portraits/women/30.jpg",
"https://randomuser.me/api/portraits/women/50.jpg",
"https://randomuser.me/api/portraits/women/68.jpg",
"https://randomuser.me/api/portraits/women/48.jpg",
"https://randomuser.me/api/portraits/women/83.jpg",
"https://randomuser.me/api/portraits/women/15.jpg",
"https://randomuser.me/api/portraits/women/1.jpg",
"https://randomuser.me/api/portraits/women/26.jpg",
"https://randomuser.me/api/portraits/women/64.jpg",
"https://randomuser.me/api/portraits/women/50.jpg",
"https://randomuser.me/api/portraits/women/82.jpg",
"https://randomuser.me/api/portraits/women/64.jpg",
"https://randomuser.me/api/portraits/women/87.jpg",
"https://randomuser.me/api/portraits/women/4.jpg",
"https://randomuser.me/api/portraits/women/92.jpg",
"https://randomuser.me/api/portraits/women/76.jpg"];
//92
let firstMan = [ 'maxime','rodney','liam','anton', 'alfonso', 'ashton','elijah','allen','hugh','ahmet','lucas','domenico','toni','norman','dag','dwayne','toby','ulf','louis','charlie','same','emre','augustas','hüseyin','darren','macit','brad','melvin','malthe','david','james','wyatt','konsta','chakib','gabriel','gerolf','atze','alexander','jessie','rayan','diego','paul','mateusz','tom','franklin','lee','raul','sebastian','kåre','onur','zélio','elouan','jeffery','vemund','jordi','marcos','albert','sander','davut','dwayne','eddie','tyrone','gino','onur','karl','ray','lucas','kaya','nixon','ignacio','lee','esat','milo','chris','kirk','bruce','pedro','geoff','haakon','asher','james','henrik','koray','noah','felix','ashton','basile','alfred','demis','tilo','archer','anton'];
//93
let firstWoman = ['holly','blanca','mia','elizabeth','gabriella','caroline','matilda','denise','buse','justine','jucélia','judith','loiva','edeltrud','teresa','susan','myrta','lily','julie','layla','gabriele','kathy','ayşegül','kaylee','diane','noelia','ekaterina','maxine','louise','sara','melissa','susie','hannah','cassandra','lillian','anja','alex','norma','lucy','esther','linda','felicity','bernarda','marie','ellie','aparecida','suzy', 'karla','elfie','cornelie','marinês','lily','elissa','sasja','irene','blanca','maya','vicenta','celia','theodora','ege','amparo','natasja','sarah','yvonne','rebecca','emma','maddison','gloria','stella','rose','sefanja','barb','lucia','bianca','laly','ruby','michelle','hazel','michelle','amy','sonialange','vivian','catherine','deborah','ceyhan','olivia','alexa','consuelo','florence','nerci','misty','kimberly'];
//200 SUR PARIS ET // 200 ALENTOURS ET //300 EN FRANCE
//74
let cities = ["Marseille",	"Lyon",	"Nice", "Nantes",	"Montpellier", "Strasbourg", "Lille",	"Rennes",	"Reims", "Saint-etienne", "Le Havre",	"Toulon",	"Grenoble", "Dijon",	"Angers",	"Nimes", "Villeurbanne",	"Aix-en-Provence",	"Le Mans", "Clermont-Ferrand",	"Brest",	"Tours",	"Amiens",	"Limoges",	"Annecy", "Perpignan", "Metz",	"Besancon",	"Rouen",	"Mulhouse",	"Caen",	"Nancy",	"Tourcoing",	"Roubaix",	"Nanterre",	"Avignon",	"Dunkerque",	"Poitiers",	"Cherbourg",	"Pau",	"Beziers",	"La Rochelle",	"Calais",	"Antibes", "Cannes",	"Merignac",	"Colmar",
	"Saint-Nazaire",	"Ajaccio",	"Bourges", "La Seyne-sur-Mer",	"Quimper", "Valence",	"Villeneuve-d'Ascq", "Pessac",	"Troyes",	"Montauban",	"Chambery",	"Niort", "Lorient", "Beauvais",	"Hyeres", "Saint-Quentin",	"Narbonne",	"Vannes",	"Frejus",	"Bondy", "Arles", "Sartrouville", "Bayonne", "Laval", "Albi", "Belfort","evreux"
];
//PARIS ET SES ARRONDISSEMENTS
//20
let locParis = ["Paris 1er Arrondissement", "Paris 2nd Arrondissement", "Paris 3eme Arrondissement", "Paris 4eme Arrondissement", "Paris 5eme Arrondissement", "Paris 6eme Arrondissement", "Paris 7eme Arrondissement", "Paris 8eme Arrondissement" , "Paris 9eme Arrondissement", "Paris 10eme Arrondissement", "Paris 11eme Arrondissement", "Paris 12eme Arrondissement", "Paris 13eme Arrondissement", "Paris 14eme Arrondissement", "Paris 15eme Arrondissement", "Paris 16eme Arrondissement", "Paris 17eme Arrondissement", "Paris 18eme Arrondissement", "Paris 19eme Arrondissement", "Paris 20eme Arrondissement"];
// LES ALENTOURS PROCHES DE PARIS
// 40
let aroundParis = ["Boulogne-Billancourt", "Saint-Denis", "Argenteuil", "Montreuil", "Vitry-sur-Seine", "Creteil", "Aubervilliers",	"Asnieres-sur-Seine",	"Colombes",	"Versailles",	"Aulnay-sous-Bois", "Courbevoie", "Rueil-Malmaison",	"Champigny-sur-Marne", "Saint-Maur-des-Fosses", "Issy-les-Moulineaux", "evry", "Noisy-le-Grand", "Drancy", "Cergy",	"Levallois-Perret", "Antony", "Clichy",	"Ivry-sur-Seine", "Neuilly-sur-Seine", "Sarcelles", "Le Blanc-Mesnil", "epinay-sur-Seine", "Villejuif", "Pantin",	"Maisons-Alfort", "Meaux", "Fontenay-sous-Bois",	"Clamart",	"Bobigny",	"Corbeil-Essonnes",	"Sevran",	"Vincennes", "Montrouge", "Meudon"];

let citiesGeo = [ { lat: '43.2961743', lon: '5.3699525' },
	{ lat: '45.6963425', lon: '4.73594802991681' },
	{ lat: '43.7009358', lon: '7.2683912' },
	{ lat: '47.2186371', lon: '-1.5541362' },
	{ lat: '43.6112422', lon: '3.8767337' },
	{ lat: '48.584614', lon: '7.7507127' },
	{ lat: '50.6305089', lon: '3.0706414' },
	{ lat: '48.1113387', lon: '-1.6800198' },
	{ lat: '49.2577886', lon: '4.031926' },
	{ lat: '45.4401467', lon: '4.3873058' },
	{ lat: '49.4938975', lon: '0.1079732' },
	{ lat: '43.1257311', lon: '5.9304919' },
	{ lat: '45.1875602', lon: '5.7357819' },
	{ lat: '47.3215806', lon: '5.0414701' },
	{ lat: '47.4739884', lon: '-0.5515588' },
	{ lat: '43.8374249', lon: '4.3600687' },
	{ lat: '45.7733105', lon: '4.8869339' },
	{ lat: '43.5298424', lon: '5.4474738' },
	{ lat: '48.0073498', lon: '0.1967379' },
	{ lat: '45.7774551', lon: '3.0819427' },
	{ lat: '48.3905283', lon: '-4.4860088' },
	{ lat: '47.3900474', lon: '0.6889268' },
	{ lat: '49.8941708', lon: '2.2956951' },
	{ lat: '45.8354243', lon: '1.2644847' },
	{ lat: '45.88975045', lon: '6.135465100226' },
	{ lat: '42.6985304', lon: '2.8953121' },
	{ lat: '49.1196964', lon: '6.1763552' },
	{ lat: '47.2380222', lon: '6.0243622' },
	{ lat: '49.4404591', lon: '1.0939658' },
	{ lat: '47.7494188', lon: '7.3399355' },
	{ lat: '49.1828008', lon: '-0.3690815' },
	{ lat: '48.6937223', lon: '6.1834097' },
	{ lat: '50.7235038', lon: '3.1605714' },
	{ lat: '50.6915893', lon: '3.1741734' },
	{ lat: '48.8924273', lon: '2.2071267' },
	{ lat: '43.9492493', lon: '4.8059012' },
	{ lat: '51.0347708', lon: '2.3772525' },
	{ lat: '46.5802596', lon: '0.340196' },
	{ lat: '49.51271975', lon: '-1.57554410903806' },
	{ lat: '43.2957547', lon: '-0.3685668' },
	{ lat: '43.3426562', lon: '3.2131307' },
	{ lat: '46.1591126', lon: '-1.1520434' },
	{ lat: '50.9488', lon: '1.87468' },
	{ lat: '43.5836', lon: '7.10905' },
	{ lat: '43.5515198', lon: '7.0134418' },
	{ lat: '44.8422361', lon: '-0.6469599' },
	{ lat: '48.0777517', lon: '7.3579641' },
	{ lat: '45.2566002', lon: '5.8490243' },
	{ lat: '41.9263991', lon: '8.7376029' },
	{ lat: '47.0805693', lon: '2.398932' },
	{ lat: '43.1007714', lon: '5.8788948' },
	{ lat: '47.9960325', lon: '-4.1024782' },
	{ lat: '39.4699014', lon: '-0.3759513' },
	{ lat: '50.6193174', lon: '3.1314002' },
	{ lat: '44.805615', lon: '-0.6308396' },
	{ lat: '48.2971626', lon: '4.0746257' },
	{ lat: '44.0175835', lon: '1.3549991' },
	{ lat: '45.5662672', lon: '5.9203636' },
	{ lat: '46.3239455', lon: '-0.4645212' },
	{ lat: '47.7477336', lon: '-3.3660907' },
	{ lat: '49.4300997', lon: '2.0823355' },
	{ lat: '43.1202573', lon: '6.1301614' },
	{ lat: '49.8465253', lon: '3.2876843' },
	{ lat: '43.1837661', lon: '3.0042121' },
	{ lat: '47.6586772', lon: '-2.7599079' },
	{ lat: '43.4330308', lon: '6.7360182' },
	{ lat: '48.9031', lon: '2.48291' },
	{ lat: '43.6776223', lon: '4.6309653' },
	{ lat: '48.9409016', lon: '2.1585037' },
	{ lat: '43.4933379', lon: '-1.475099' },
	{ lat: '48.0710377', lon: '-0.7723499' },
	{ lat: '43.9277552', lon: '2.147899' },
	{ lat: '47.6379599', lon: '6.8628942' },
	{ lat: '49.0268903', lon: '1.1510164' } ];
let locParisGeo = [ { lat: '48.8621576', lon: '2.33703564353732' },
	{ lat: '48.868743', lon: '2.341688' },
	{ lat: '48.86387315', lon: '2.36178592968275' },
	{ lat: '48.85614835', lon: '2.355781939' },
	{ lat: '48.84600915', lon: '2.34461904940945' },
	{ lat: '12.10456785', lon: '15.0739025126348' },
	{ lat: '48.85728135', lon: '2.3204020168997' },
	{ lat: '48.8774763', lon: '2.31732443836457' },
	{ lat: '48.8734832', lon: '2.3397879' },
	{ lat: '48.87180125', lon: '2.3577861688909' },
	{ lat: '48.8587182', lon: '2.37896039635983' },
	{ lat: '48.84081555', lon: '2.38836903404007' },
	{ lat: '48.83257615', lon: '2.35586867089955' },
	{ lat: '48.83311715', lon: '2.32683755915287' },
	{ lat: '48.84136315', lon: '2.30037268222123' },
	{ lat: '48.8636428', lon: '2.27638258133067' },
	{ lat: '48.8845114', lon: '2.32229595755345' },
	{ lat: '48.89212125', lon: '2.34446359889139' },
	{ lat: '48.8829974', lon: '2.38190290309734' },
	{ lat: '48.86533265', lon: '2.39956507413333' } ];
let aroundParisGeo = [ { lat: '48.8356649', lon: '2.240206' },
	{ lat: '48.935773', lon: '2.3580232' },
	{ lat: '48.9479069', lon: '2.2481797' },
	{ lat: '50.4638918', lon: '1.7631125' },
	{ lat: '48.7876', lon: '2.39164' },
	{ lat: '48.7771486', lon: '2.4530731' },
	{ lat: '48.9146078', lon: '2.3821895' },
	{ lat: '48.9105948', lon: '2.2890454' },
	{ lat: '48.922788', lon: '2.2543577' },
	{ lat: '48.8035403', lon: '2.1266886' },
	{ lat: '48.934231', lon: '2.499789' },
	{ lat: '48.8953328', lon: '2.2561602' },
	{ lat: '48.87778', lon: '2.1802832' },
	{ lat: '48.8137759', lon: '2.5107384' },
	{ lat: '48.8033057', lon: '2.4853015' },
	{ lat: '48.8250508', lon: '2.273457' },
	{ lat: '48.6241665', lon: '2.4289667' },
	{ lat: '48.8493972', lon: '2.5519571' },
	{ lat: '48.9229803', lon: '2.4455201' },
	{ lat: '49.0527528', lon: '2.0388736' },
	{ lat: '48.892956', lon: '2.2881683' },
	{ lat: '48.753554', lon: '2.2959423' },
	{ lat: '48.9026', lon: '2.30551' },
	{ lat: '48.8122302', lon: '2.3872525' },
	{ lat: '48.884683', lon: '2.2695658' },
	{ lat: '48.9960813', lon: '2.3796245' },
	{ lat: '48.9385489', lon: '2.4631476' },
	{ lat: '48.9525181', lon: '2.3145039' },
	{ lat: '48.7921098', lon: '2.3633048' },
	{ lat: '48.8965023', lon: '2.4019804' },
	{ lat: '48.8012045', lon: '2.4309703' },
	{ lat: '48.9582708', lon: '2.8773541' },
	{ lat: '48.8490721', lon: '2.4749347' },
	{ lat: '48.800368', lon: '2.2630292' },
	{ lat: '48.906387', lon: '2.4452231' },
	{ lat: '48.6137734', lon: '2.4818087' },
	{ lat: '48.9392142', lon: '2.5257254' },
	{ lat: '48.8474508', lon: '2.4396714' },
	{ lat: '48.8144', lon: '2.31606' },
	{ lat: '48.8126688', lon: '2.2385432' } ];


/** FUNCTION **/
var argv = parseInt(process.argv[2], 10);
if (isNaN(argv))
	argv = 500;
argv > 1000 ? argv = 1000 : argv;
let sexPref = ["male", "female", "bi", "other"];
var firstname;
var lastname;
var mail;
var username;
var bio;
var avatar;
var pass;
var sex;
var token;
var imgRandom;
var interest;
var date;
var min = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'];
var maj = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'];
var chiffre = ['0','1', '2', '3', '4', '5', '6', '7', '8', '9'];
var spe = ['!', '@', '#', '$', '%', '&', '*', '?', '<', '>'];

function getRandomInt(max) {
	return Math.floor(Math.random() * Math.floor(max));
}

function randomPass () {
	return (min[getRandomInt(26)] + maj[getRandomInt(26)]
		+ chiffre[getRandomInt(10)] + spe[getRandomInt(10)]
		+ min[getRandomInt(26)] + maj[getRandomInt(26)])
}

function pickInterest(tab) {
	let interest = [];
	let max = getRandomInt(11) + 1;
	for (var i = 0; i < max; i++) {
		let elem = tab[getRandomInt(tab.length)];
		if (!interest.includes(elem))
			interest.push(elem);
	}
	return (interest);
}
async function setProfil(birthdate, gender, tabInterest, city, loc, imgRandom) {
	if (gender === "female") {
		firstname = firstWoman[getRandomInt(93)];
	} else if (gender === "male") {
		firstname = firstMan[getRandomInt(92)];
	} else {
		if (getRandomInt(2) === 0)
			firstname = firstWoman[getRandomInt(93)];
		else
			firstname = firstMan[getRandomInt(92)];
	}
	firstname = firstname.charAt(0).toUpperCase() + firstname.slice(1);
	lastname = faker.name.lastName().toUpperCase();
	mail = faker.internet.email();
	username = faker.internet.userName();
	bio = faker.lorem.paragraph();
	pass = randomPass();
	sex = sexPref[getRandomInt(4)];
	token = uuidv1();
	if (gender === 'female') {
		avatar = woman[getRandomInt(161)];
	} else if (gender === 'male') {
		avatar = man[getRandomInt(119)];
	} else {
		if (getRandomInt(2) === 0)
			avatar = woman[getRandomInt(161)];
		else
			avatar = man[getRandomInt(118)];
	}
	interest = pickInterest(tabInterest);
	date = new Date();
	if (firstname && lastname && username && mail && birthdate && bio && pass
		&& gender && sex && city && loc && token && avatar
		&& imgRandom && date)
	{
		pass = bcrypt.hashSync(pass, 10);
		data = [mail, username, lastname, firstname, pass, gender, sex, bio, birthdate, city, loc.lat, loc.lon, token, "confirmed", date];
		let res = await db.seedUser(data);
		if (res !== null)
		{
			db.seedImg([avatar, res, 1, imgRandom, res, 0]);
			db.seedInterestUser(res, interest);
		}
	}
}

	/*
async function getImages() {
	let tabImg1, tabImg2;
	let res = await axios.get('https://picsum.photos/v2/list?limit=100');
	if (res.data)
		tabImg1 = res.data.map(e => (e.download_url));
	res = await axios.get('https://picsum.photos/v2/list?limit=100');
	if (res.data)
		tabImg2 = res.data.map(e => (e.download_url));
	return (tabImg1.concat(tabImg2));
}
*/
(async function () {
	console.log("\x1b[35m", 'Initializing queries...', "\x1b[0m");
	let tabImg = [];
	for (var i = 0; i < 200; i++)
		tabImg.push(`https://picsum.photos/id/${getRandomInt(1073)}/200/200`);
	var tabInterest = await dbInt.getIdInterest();
	tabInterest = tabInterest.map(e => (e.id_interest));
	let gender;
	let birthdate;
	let nbcity;
	let city;
	let loc;
	for (var j = 0; j < argv; j++) {
		birthdate = faker.date.between('1959-01-01', '2001-07-31');
		if (j < argv * 0.2)
			gender = "other";
		else if (j < argv * 0.5)
			gender = "female";
		else
			gender = "male";
		if (j < argv * 0.4) {
			nbcity = getRandomInt(20);
			city = locParis[nbcity];
			loc = locParisGeo[nbcity];
		} else if (j < argv * 0.7){
			nbcity = getRandomInt(40);
			city = aroundParis[nbcity];
			loc = aroundParisGeo[nbcity];
		} else {
			nbcity = getRandomInt(74);
			city = cities[nbcity];
			loc = citiesGeo[nbcity];
		}
		imgRandom = tabImg[getRandomInt(200)];
		await setProfil(birthdate, gender, tabInterest, city, loc, imgRandom);
		if (j > 0 && j % 100 === 0)
			console.log("\x1b[33m", '100 profils inserted \u2726', "\x1b[0m");
		if (j === argv - 1)
		{
			console.log("\x1b[32m", 'Every profils inserted \u2713', "\x1b[0m", "\x1b[37m", "\nWaiting for closing database connections...", "\x1b[0m");
			setTimeout( function() {
				db.stopSeed();
			}, 1000);
		}
	}
})()
