import React, { useState, useEffect, useRef, useContext, useCallback } from 'react';
import { Store } from '../../store';
import axios from 'axios';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import { faUserCircle } from '@fortawesome/free-solid-svg-icons'
import { faTimesCircle } from '@fortawesome/free-solid-svg-icons'

export default function Image()
{
	const { state, dispatch } = useContext(Store);
	const fileInput = useRef(null);
	const [images, setImages] = useState([]);
	const [error, setError] = useState(null);
	const callback = useCallback(addProfilImg);

	//LOAD IMGS FROM DATABASE
	useEffect(() => {
		async function fetchData() {
			try {
				const res = await axios.get(`/user/img/${state.id_session}`);
				if (res.data)
					setImages(res.data);
				else
					setError('Une erreur est survenue.');
			} catch (err) {
				//console.error(err);
				setError('Une erreur est survenue.');
			}
		}
		fetchData();
	}, [state.id_session, error])

	useEffect(() => {
		if (images.length > 0)
		{
			if (images.every(e => (e.profil === 0)))
				callback(images[0].id_img);
		}
	}, [images, callback])


	//UPLOAD A FILE ON SERVER AND UPDATE THE images STATE
	function upload(img) {
		var userIMG = new FormData();
		userIMG.append('file', img);
		userIMG.append('token', state.token);
		userIMG.append('id', state.id_session);
		async function uploadImg() {
			try {
				let res = await axios.post(`/upload/img/${state.id_session}`,
					userIMG);
					if (res.data.error)
						setError(res.data.error || 'Une erreur est survenue.');
					else
						setImages([...images, res.data]);
			} catch (err) {
				//console.error(err);
				setError('Une erreur est survenue.');
			}
		}
		uploadImg();
	}

	//IS CALLED WHEN ADDING A FILE AND CHECK FEW THNGS BEFORE CALLING UPLOAD
	function toggleInput() {
		let img = fileInput.current.files[0];
		if (img)
		{
			if (img.size > 1000000)
				setError("L'image est supérieur à 1mo");
			else if (!img.type.match(/image\/?(png)|(jpg)|(jpeg)/))
				setError("L'image ne possède pas le bon format");
			else if (images.length > 4)
				setError("5 images maximum");
			else
			{
				if (error)
					setError(null);
				upload(img);
				fileInput.current.value = '';
			}
		}
	}

	//PUT THE SELECTED IMG AS THE PROFIL IMAGE
	async function addProfilImg(id) {
		let i = images.findIndex(e => (e.id_img === id));
		if (!images[i].profil)
		{
			try {
				let res = await axios.post('/user/img/profil/switch',
					{id: state.id_session, id_img : id,
						token: state.token});
				if (res.data)
				{
					let j = images.findIndex(e => (e.profil === 1));
					images[i].profil = 1;
					if (j > -1)
						images[j].profil = 0;
					dispatch({type: 'CHANGE_AVATAR', payload: images[i].path});
					setImages([...images]);
				}
				else
					setError('Une erreur est survenue.');
			} catch (err) {
				//console.error(err);
				setError('Une erreur est survenue.');
			}
		}
	}

	//DELETE AN IMG
	function deleteImg(id) {
		let i = images.findIndex(e => (e.id_img === id));
		if (images[i])
		{
			if (images[i].profil === 1 && images.length === 1)
				dispatch({type: 'CHANGE_AVATAR',
					payload: '/public/img/avatar.png'});
			axios.post('/user/img/delete', {id_img: id, path: images[i].path,
				id: state.id_session, token: state.token});
			setImages(images.filter(e => (e.id_img !== id)));
		}
	}

	//DEAL THE DRAG AND DROP EVENTS
	function dragDrop(e) {
		e.preventDefault();
		document.getElementById('drag').style.border = '3px dashed black';
		let data = e.dataTransfer.files;
		upload(data[0]);
	}
	function dragOver(e) {
		e.preventDefault();
		document.getElementById('drag').style.border = '3px dashed green';
	}
	function dragLeave(e) {
		e.preventDefault();
		document.getElementById('drag').style.border = '3px dashed black';
	}

	return (
		<>
<h3 className="image-box-title">Mes photos:</h3>
<ul className="listImg">
		{images.map((img, index) => (
			<li className="listImgProfil" key={index}>
				<img className={img.profil ? 'user-img profilImg' : 'user-img'} src={img.path} alt={'userImage' + index} />
				<div className='overlay' id={img.id_img}>
					<FontAwesomeIcon icon={faUserCircle} className='favourite' onClick={() => addProfilImg(img.id_img)}/>
					<span className ='tooltip'>Mettre en profil</span>
					<FontAwesomeIcon icon={faTimesCircle} className='delete' onClick={() => deleteImg(img.id_img)} />
					<span className ='tooltip'>Supprimer</span>
				</div>
				</li>))}
					{images.length < 5 && <div id='drag' className='user-img' onDrop={dragDrop} onDragOver={dragOver} onDragLeave={dragLeave}>
						<label htmlFor='img'>
								Cliquez ou déposez vos images ici<br/>
									(5/max, 1mo max, .jpeg, .jpg, .png)
								<input type="file" ref={fileInput} id='img' onChange={toggleInput} accept='image/jpeg, image/jpg, image/png' style={{display:'none'}}/>
									{error && <p className='error'>{error}</p>}
								</label>
								</div>}
							</ul>
					</>
	);
}
